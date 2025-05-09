for test_case in range(1, 11): 
    N = int(input())
    building_list = list(map(int, input().split()))
    answer = 0
    
    for i in range(2, N - 2):
        lhighest = max(building_list[i - 1], building_list[i - 2])
        rhighest = max(building_list[i + 1], building_list[i + 2])
        best_highest = max(lhighest, rhighest) 
        if best_highest < building_list[i]:
            answer += building_list[i] - best_highest
                
    print(f"#{test_case} {answer}")
