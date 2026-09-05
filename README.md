# 42 C++ Modules

C++의 클래스, 객체 수명, 상속·다형성, 예외, 템플릿과 STL을 **9개 모듈·35개 독립 예제**로 구현한 42 Seoul 학습 저장소입니다.

고정소수점 수의 연산자 오버로딩부터 문서 생성 클래스, 범위를 검사하는 배열 템플릿, 반복자를 제공하는 스택까지 단계적으로 다룹니다. 각 `exXX/`에 구현과 실행용 `main.cpp` 또는 테스트 코드, Makefile이 함께 있습니다.

## 모듈별 구현

| 모듈 | 예제 | 구현 내용 |
| --- | --- | --- |
| [00](cpp_module_00) | ex00–02 | 대문자 출력, 전화번호부, 계좌 상태와 거래 로그 |
| [01](cpp_module_01) | ex00–06 | 객체 생성·해제, 포인터와 참조, 파일 문자열 치환, 멤버 함수 포인터와 로그 필터 |
| [02](cpp_module_02) | ex00–03 | 고정소수점 클래스, 산술·비교 연산자, 삼각형 내부의 점 판정 |
| [03](cpp_module_03) | ex00–03 | ClapTrap을 확장하는 상속 구조와 DiamondTrap의 다중 상속 |
| [04](cpp_module_04) | ex00–03 | 가상 함수, 객체 복사, 추상 클래스, Materia 인터페이스 |
| [05](cpp_module_05) | ex00–03 | 등급 검사와 예외, 서명·실행 권한, 이름에 따른 Form 생성 |
| [06](cpp_module_06) | ex00–02 | 문자·정수·실수 변환, 포인터 → 정수 → 포인터 변환, 실행 중 타입 식별 |
| [07](cpp_module_07) | ex00–02 | 함수 템플릿, 배열 순회 함수, 복사와 범위 검사를 가진 Array |
| [08](cpp_module_08) | ex00–02 | 컨테이너 검색, 최소·최대 간격 계산, 반복 가능한 MutantStack |

## 먼저 볼 코드

- **[Fixed와 연산자](cpp_module_02/ex02/FixedOperator.cpp):** 고정소수점 표현에 산술·비교·증감 연산을 연결합니다.
- **[Intern의 Form 생성](cpp_module_05/ex03/Intern.cpp):** 문서 이름과 멤버 함수 포인터 배열을 연결해 세 종류의 문서를 생성합니다.
- **[Array 템플릿](cpp_module_07/ex02/Array.hpp):** 별도 저장 공간에 원소를 복사하고, 인덱스 범위를 벗어나면 예외를 던집니다.
- **[Span](cpp_module_08/ex01/Span.cpp):** 정렬한 복사본의 인접 원소로 최소 간격을, 양 끝값으로 최대 간격을 계산합니다.
- **[MutantStack](cpp_module_08/ex02/MutantStack.hpp):** `std::stack`의 내부 컨테이너 반복자를 `begin()`, `end()`로 노출합니다.

## 빌드와 실행

각 예제 디렉터리에서 독립적으로 빌드합니다. 다음은 정수 집합의 간격을 구하는 Span 예제입니다.

```bash
cd cpp_module_08/ex01
make
./ex01
```

첫 입력 `6, 3, 17, 9, 11`의 최소 간격은 `2`, 최대 간격은 `14`입니다. 이어서 용량 초과·원소 부족 예외, 10,001개 값의 간격, 반복자 구간 삽입을 실행합니다.

정리는 해당 디렉터리에서 `make fclean`으로 수행합니다. 모든 예제의 실행 파일 이름과 추가 인자는 [실행 안내](docs/running.md)에 있습니다.

## 언어 표준과 호환성

Makefile은 C++98을 지정합니다. 00–04는 링크 단계에서 `clang++`, 05–08은 컴파일·링크에 `c++`을 사용합니다.

06/ex00의 `std::stoi·stof·stod`는 C++11 기능이며, 06/ex01은 `uintptr_t` 선언을 위한 헤더가 필요합니다. 이 두 예제의 실행 명령은 [호환성 안내](docs/running.md#호환성)에 별도로 정리했습니다.

00/ex02 테스트의 `std::mem_fun_ref`는 C++17 표준에서 제거된 함수 어댑터입니다. 현재 코드에는 C++98 형태가 남아 있으며, 이후 표준의 대응 수단은 람다와 `std::mem_fn`입니다. [표준 변경 기록](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0636r2.html)

## 개발 기록

개발 이력에는 [템플릿 const 오버로드 추가](https://github.com/tjung03/42_cpp_module/commit/c751394f8c2adbe5bfd1391977d5c321af2784bd), [범위 기반 반복문의 C++98 형태 변경](https://github.com/tjung03/42_cpp_module/commit/f103f0431b97a99e57d888580dcfcfd9ee143922), [macOS 관련 수정](https://github.com/tjung03/42_cpp_module/commit/2e4045e976eb5eccedbcc856f1406fa64d9a0ca2)이 남아 있습니다.
