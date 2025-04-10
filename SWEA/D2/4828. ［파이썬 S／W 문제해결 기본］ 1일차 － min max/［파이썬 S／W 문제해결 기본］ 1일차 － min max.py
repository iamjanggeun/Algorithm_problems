T = int(input())

for test_case in range(1, T + 1):
    N = int(input())
    list1 = list(map(int, input().split()))
    
    max_value = list1[0]
    min_value = list1[0]
    
    for i in list1:
        if(i < min_value):
            min_value = i
        if(i > max_value):
            max_value = i
            
    answer = max_value - min_value
    
    print(f"#{test_case} {answer}")
        
    
    