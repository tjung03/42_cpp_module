# 예제 실행 안내

[README로 돌아가기](../README.md)

각 `cpp_module_XX/exYY/` 안에서 `make`한 뒤 아래 실행 파일을 호출합니다. 00–04는 Make의 C++ 암묵 규칙으로 오브젝트를 만들고 `clang++`로 링크하므로 C++ 컴파일러와 Clang이 필요합니다. 05–08은 Makefile의 `CPP=c++`을 사용합니다.

| 모듈 | 예제 → 실행 파일 |
| --- | --- |
| 00 | ex00 → `megaphone`, ex01 → `phonebook`, ex02 → `account` |
| 01 | ex00·01 → `zombie`, ex02 → `print`, ex03 → `unnecessary_violence`, ex04 → `replace`, ex05 → `harl`, ex06 → `harlFilter` |
| 02 | ex00–03 → `a.out` |
| 03 | ex00 → `claptrap`, ex01 → `scavtrap`, ex02 → `fragtrap`, ex03 → `diamondtrap` |
| 04 | ex00 → `Animal`, ex01 → `brain`, ex02 → `abstract`, ex03 → `materia` |
| 05 | ex00 → `bureaucrat`, ex01 → `form`, ex02 → `multi_form`, ex03 → `intern` |
| 06 | ex00 → `static`, ex01 → `reinterpret`, ex02 → `dynamic` |
| 07 | ex00 → `templatess`, ex01 → `iter`, ex02 → `array` |
| 08 | ex00 → `easyfind`, ex01 → `ex01`, ex02 → `mutantstack` |

## 입력이 필요한 예제

| 예제 | 입력 |
| --- | --- |
| 00/ex00 | `./megaphone "hello"` |
| 00/ex01 | `./phonebook` 실행 후 `ADD`, `SEARCH`, `EXIT` |
| 01/ex04 | `./replace hibyehello.txt hi HI` |
| 01/ex06 | `./harlFilter WARNING` |
| 06/ex00 | `./static 42` |

01/ex04는 파일명에서 첫 번째 점 앞까지를 사용해 `.replace` 파일을 만듭니다. 치환 문자열에 검색 문자열이 포함되면 입력 오류로 처리합니다.

## 호환성

06/ex00은 다음과 같이 C++11을 지정해 실행할 수 있습니다.

```bash
cd cpp_module_06/ex00
make re CPPFLAGS='-pedantic -std=c++11 -Wall -Wextra -Werror'
./static 42
```

06/ex01은 `uintptr_t` 선언을 불러오도록 컴파일 옵션에 헤더를 추가합니다.

```bash
cd cpp_module_06/ex01
make re CPPFLAGS='-pedantic -std=c++11 -Wall -Wextra -Werror -include cstdint'
./reinterpret
```

두 명령의 `cd` 경로는 저장소 루트 기준입니다.

07/ex02의 unsigned 인덱스와 0을 비교하는 조건은 GCC의 `-Werror=type-limits`에 걸립니다. 01/ex04는 C++98 설정과 `std::string`을 받는 파일 열기 호출이 맞지 않습니다. 이 예제들은 컴파일러 진단을 확인해야 합니다.

04/ex01의 `main.cpp`에는 원본 해제 후 얕게 복사한 `WrongCat`에 접근하는 비교 코드가 포함되어 있습니다. 객체 수명 문제를 다루는 학습 예제입니다.
