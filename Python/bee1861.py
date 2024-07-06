def main() -> None:
    kills: dict = {}
    grave_yard = set()

    while True:
        try:
            murder = input()
            killer, killed = murder.split()

            grave_yard.add(killed)

            if killed in kills:
                kills.pop(killed)
            if killer in grave_yard:
                continue
            if killer in kills:
                kills[killer] += 1
            else:
                kills[killer] = 1
        except EOFError:
            break

    kills = dict(sorted(kills.items()))

    print('HALL OF MURDERERS')
    for killer, count in kills.items():
        print(f'{killer} {count}')
    
    
if __name__ == '__main__':
    main()