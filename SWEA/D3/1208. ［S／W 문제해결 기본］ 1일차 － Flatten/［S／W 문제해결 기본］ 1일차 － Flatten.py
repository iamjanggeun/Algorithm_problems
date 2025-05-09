#1208 flatten
for test_case in range(1, 11):
    dump = int(input())
    box_height = list(map(int, input().split()))
    for i in range(dump):
        answer = 0
        max_box = max(box_height)
        min_box = min(box_height)
        max_idx = box_height.index(max_box)
        min_idx = box_height.index(min_box)
        if(max_box - min_box > 1):
            box_height[max_idx] -= 1
            box_height[min_idx] += 1
        else:
            break
    answer = max(box_height) - min(box_height)
    print(f"#{test_case} {answer}")