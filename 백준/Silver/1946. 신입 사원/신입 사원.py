import sys

# 테스트 케이스 수 입력
T = int(sys.stdin.readline())

for _ in range(T):
    # 지원자 수 입력
    N = int(sys.stdin.readline())

    # 지원자 정보 입력
    applicants = []
    for i in range(N):
        documents, interview = map(int, sys.stdin.readline().split())
        applicants.append((documents, interview))

    # 서류심사 성적을 기준으로 오름차순 정렬
    applicants.sort()

    # 면접심사 순위 최소값 설정
    interview_rank = applicants[0][1]
    count = 1

    # 탐색 시작
    for i in range(1, N):
        # 면접심사 순위가 이전 지원자보다 높은 경우
        if applicants[i][1] < interview_rank:
            interview_rank = applicants[i][1]
            count += 1

    print(count)
