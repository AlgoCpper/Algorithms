import java.util.*;
class Solution {
    public int[] solution(int[] fees, String[] records) {
        int[] answer = {};
        Map<Integer, Car> carmap = new HashMap<>();
        
        for (String record : records) {
            String[] elements = record.split(" ");
            String time = elements[0];
            int carNum = Integer.parseInt(elements[1]);
            String inAndOut = elements[2];
            Car find = carmap.getOrDefault(carNum, new Car());
            find.move(time, inAndOut);
            carmap.put(carNum, find);
        }
        
        for (Car car : carmap.values()) {
            if (car.in) {
                car.move("23:59", "OUT");
            }
            System.out.println(car.sum);
        }
        
        List<CarTime> times = new ArrayList<>();
        for (int key : carmap.keySet()) {
            times.add(new CarTime(key, carmap.get(key).sum, fees));
        }
        
        Collections.sort(times);
        answer = times.stream()
            .mapToInt(CarTime::cost)
            .toArray();
        
        return answer;
    }
}

class Car {
    public int timeIn = 0;
    public int sum = 0;
    boolean in = false;
    
    public void move(String time, String inAndOut) {
        String[] hourAndMinute = time.split(":");
        int h = Integer.parseInt(hourAndMinute[0]);
        int m = Integer.parseInt(hourAndMinute[1]);
        int t = h * 60 + m;
        boolean carIn = inAndOut.equals("IN");
        
        if (carIn) {
            timeIn = t;
            in = true;
            return;
        }
        
        sum += t - timeIn;
        in = false;
    }
}

class CarTime implements Comparable {
    public int carNum;
    public int time;
    public int[] fees;
    
    public CarTime(int carNum, int time, int[] fees) {
        this.carNum = carNum;
        this.time = time;
        this.fees = fees;
    }
    
    public int compareTo(Object o) {
        CarTime c = (CarTime) o;
        return this.carNum - c.carNum;
    }
    
    public int cost() {
        int cost = fees[1];
        if (time <= fees[0]) return cost;
        return cost + ((time - fees[0] + fees[2] - 1) / fees[2]) * fees[3];
    }
}