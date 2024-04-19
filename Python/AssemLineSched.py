def assembly_line_scheduling(a, t, e, x, n):
    T1 = [0] * n
    T2 = [0] * n
    T1[0] = e[0] + a[0][0]
    T2[0] = e[1] + a[1][0]

    for i in range(1, n):
        T1[i] = min(T1[i-1] + a[0][i], T2[i-1] + t[1][i] + a[0][i])
        T2[i] = min(T2[i-1] + a[1][i], T1[i-1] + t[0][i] + a[1][i])

    return min(T1[n-1] + x[0], T2[n-1] + x[1])

def main():
    n = int(input("Enter the number of stations: "))

    a = [[0] * n for _ in range(2)]
    t = [[0] * n for _ in range(2)]
    e = [0] * 2
    x = [0] * 2

    print("Enter the processing time for each station on each line:")
    for i in range(2):
        print("Line", i + 1, end=": ")
        a[i] = list(map(int, input().split()))

    print("Enter the transfer time between stations:")
    for i in range(2):
        print("Line", i + 1, end=": ")
        t[i][1:] = list(map(int, input().split()))

    print("Enter the entry time for each line:")
    for i in range(2):
        print("Line", i + 1, end=": ")
        e[i] = int(input())

    print("Enter the exit time for each line:")
    for i in range(2):
        print("Line", i + 1, end=": ")
        x[i] = int(input())

    print("Minimum time to exit:", assembly_line_scheduling(a, t, e, x, n))

if __name__ == "__main__":
    main()
