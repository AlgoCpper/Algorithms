package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.StringTokenizer;

public class BoJ_17484_진우의_달_여행_Small {

	static int min = Integer.MAX_VALUE;

	static int[] dy = {-1, 0, 1};

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		int[][] arr = new int[n][m];
		// 3차원의 0: 왼쪽 위에서 가져온 최솟값, 1: 위에서 가져온 최솟값, 2: 오른쪽 위에서 가져온 최솟값
		int[][][] dp = new int[n][m][3];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		// dp 초기화
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 3; j++) {
				dp[0][i][j] = arr[0][i];
			}
		}

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// 왼쪽 위, 오른쪽 위가 모두 범위 내인 경우
				if (j-1 >= 0 && j+1 < m) {
					// 연속해서 같은 방향에서 가져올 수 없으므로 dp[i-1][j-1][0]를 제외하고 최솟값을 가져옴
					dp[i][j][0] = arr[i][j] + Math.min(dp[i-1][j-1][1],dp[i-1][j-1][2]);
					// 연속해서 같은 방향에서 가져올 수 없으므로 dp[i-1][j][1]을 제외하고 최솟값을 가져옴
					dp[i][j][1] = arr[i][j] + Math.min(dp[i-1][j][0],dp[i-1][j][2]);
					// 연속해서 같은 방향에서 가져올 수 없으므로 dp[i-1][j+1][2]를 제외하고 최솟값을 가져옴
					dp[i][j][2] = arr[i][j] + Math.min(dp[i-1][j+1][0],dp[i-1][j+1][1]);
				}
				// 오른쪽 위가 범위 바깥인 경우
				else if (j-1 >= 0) {
					dp[i][j][0] = arr[i][j] + Math.min(dp[i-1][j-1][1],dp[i-1][j-1][2]);
					dp[i][j][1] = arr[i][j] + Math.min(dp[i-1][j][0],dp[i-1][j][2]);
					dp[i][j][2] = 1000; // 오른쪽 위에서 가져올 수 없으므로 가능한 정답의 최댓값보다 큰 수를 할당
				}
				// 왼쪽 위가 범위 바깥인 경우
				else {
					dp[i][j][0] = 1000; // 왼쪽 위에서 가져올 수 없으므로 가능한 정답의 최댓값보다 큰 수를 할당
					dp[i][j][1] = arr[i][j] + Math.min(dp[i-1][j][0],dp[i-1][j][2]);
					dp[i][j][2] = arr[i][j] + Math.min(dp[i-1][j+1][0],dp[i-1][j+1][1]);
				}
			}
		}
		int minValue = dp[n-1][0][0];   // 최솟값을 찾기 위한 임시 변수
		// dp[n-1]에서 최솟값을 찾아야 함
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 3; j++) {
				minValue = Math.min(minValue, dp[n-1][i][j]);
			}
		}
		int answer = minValue;  // 정답 할당

		System.out.println(answer);
	}
}


