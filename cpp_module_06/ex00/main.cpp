#include "Converter.hpp"
#include "Exception.hpp"

// 숫제 제한 및 특수 값을 처리하기 위해 필요한 헤더 사용 가능.

// char		'c', 'a'	: 출력되지 않는 문자는 입력으로 사용하지 않는다. char 로 변환할 수 없으면 에러 메세지 출력
// int		0, -42
// float	0.0f -4.2f	: 유사 상수인 +inff, -inff, nanf 도 표현
							// float 범위 밖에 있으면 +inff(양수 범위 밖), -inff(음수 범위 밖), -nanf(숫자가 아닐 때)
// double	0.0, -4.2	: 유사 상수인 +inf, -inf, nan 도 표현
							// double 범위 밖에 있으면 +inf(양수 범위 밖), -inf(음수 범위 밖), -nan(숫자가 아닐 때)

// 문자(char)와 10진법 표기만 입력으로 받음 - 아니면 에러 메세지 출력
// 구분
// 1. 매개 변수로 전달된 리터럴의 유형을 감지
// 2. 매개 변수 값을 실제 유형값으로 변환
// 3. 해당 값을 char, int, float, double 의 형태로 변환하여 출력
//
// 변환이 의미 없거나 오버플로우가 발생하면, 사용자에게 유형 변환이 불가함을 알리는 에러 메세지를 출력 (impossible)

// - functions -
// detectLiteralType();
// convertStringToType();
// printValueType();

void	checkInvalidNumOfArguments(int argc)
{
	if (argc != 2)
		throw (InvalidMainArguException());
}

int	main(int argc, char *argv[])
{
	// 공백 받고 싶으면 이렇게 입력 ->
	//										./conversion " "  혹은  ./conversion "' '"
	// (문자 입력에는 큰 따옴표 사용)
	try {
		checkInvalidNumOfArguments(argc);
		std::string	input(argv[1]);
		Converter	converter(input);
	} catch (const InvalidMainArguException &e) {
		std::cerr<<e.what()<<std::endl;
	} catch (const std::invalid_argument &e) {
		std::cerr<<e.what()<<": invalid_argument"<<std::endl;
	} catch (const std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}
	return (0);
}
