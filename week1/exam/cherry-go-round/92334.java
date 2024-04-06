import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        
        Map<String, User> map = new HashMap<>();
        for (String id : id_list) {
            User user = new User(id);
            map.put(id, user);
        }
        
        Set<Report> reports = new HashSet<>();
        
        for (String s : report) {
            String[] split = s.split(" ");
            String fromId = split[0];
            String toId = split[1];
            Report r = new Report(fromId, toId);
            
            if (reports.contains(r)) continue;
            reports.add(r);
            User to = map.get(toId);
            to.reported++;
        }
        
        for (Report r : reports) {
            User from = map.get(r.fromId);
            User to = map.get(r.toId);
            if (to.reported >= k) {
                from.mail++;
            }
        }
        
        return Arrays.stream(id_list)
            .map(map::get)
            .mapToInt(user -> user.mail)
            .toArray();
    }
}

class User {
    public String id;
    public int reported;
    public int mail;
    
    public User(String id) {
        this.id = id;
        reported = 0;
        mail = 0;
    }
    
    @Override
    public boolean equals(Object o) {
        
        if (this == o) {
            return true;
        }
        
        if (o == null || this.getClass() != o.getClass()) {
            return false;
        }
        
        User user = (User) o;
        return this.id == user.id;
    }
    
    @Override
    public int hashCode() {
        return id.hashCode();
    }
}

class Report {
    public String fromId;
    public String toId;
    
    public Report(String fromId, String toId) {
        this.fromId = fromId;
        this.toId = toId;
    }
    
    @Override
    public boolean equals(Object o) {
        
        if (this == o) {
            return true;
        }
        
        if (o == null || this.getClass() != o.getClass()) {
            return false;
        }
        
        Report report = (Report) o;
        return this.fromId.equals(report.fromId)
            && this.toId.equals(report.toId);
    }
    
    @Override
    public int hashCode() {
        return fromId.hashCode() * 31 + toId.hashCode();
    }
}