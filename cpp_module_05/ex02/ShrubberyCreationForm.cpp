#include "ShrubberyCreationForm.hpp"

const char	*ShrubberyCreationForm::_ASCII_TREE =
	""
	"                                                        ,\n"
	"                                            .__ ._       \\_.          \n"
	"                                     _, _.  '  \\/   \\.-  /            \n"
	"                                      \\/     .-_`   // |/     \\,      \n"
	"                     .-\"\"\"\"-.          \\.   '   \\`. ||  \\.-'  /       \n"
	"                    F        Y        .-.`-(   _/\\ V/ \\\\//,-' >-'   ._,\n"
	"                   F          Y   .__/   `. \\.   ' J   ) ./  / __._/  \n"
	"                  J         \\, I    '   _/ \\  \\  | |  / /  .'-'.-' `._,\n"
	"           (       L   \\_.--.| \\_.      ' .___ `\\: | / .--'.-'\"     \\ \n"
	"         \\ '\\    .  L   /    \\\\/        ._/`-.`  \\ .'.' .'---./__   ' \n"
	"    \\__  '\\ ) \\._/   `-.__. ` \\\\_. '   .---.  \\     /  /  ,   `  `    \n"
	"  --'  \\\\  ): // \\,            `-.`__.'     `- \\  /   / _/-.---.__.- . \n"
	"     _.-`.'/ /'\\_, ._     >--.-\"\"'____.--\"`_     '   /.'..' \\   \\   _/`\n"
	" _ .---._\\ \\'/ '__./__.-..  / .-|(    x_.-'___  |   :' /    _..---_' \n"
	" .:' /`\\ `. `..'.--'\\      /.' /`-`._  `-,'   ` '   I '_.--'__--..___.--._.-\n"
	"     `  `. `\\/'/  _.   _.-'      _.____./ .-.--\"\"-. .-\"    ' _..-.---'   \n"
	"  -._ .--.\\ / /-./     /   .---'-//.___. .-'       \\__ .--.  `    `.     '`-\n"
	" ,--'/.-. ^.   .-.--.  ` _/    _//     ./   _..   .'  `.    \\ \\    |_.\n"
	"    /' | >.   ' | \\._.-       '    _..'  `.' . `.       )    | |\\  `          \n"
	"  ./ \\ \\'  ) c| /  \\     \\_..  .--'    ,\\ \\_/`  :    )  (`-. `.|`\\            \n"
	"   \\'  / ,-.  | ` ./`  ._/ `\\'.--.,-((  `.`.__ |   _/   \\    |)  `--._/`     \n"
	"______'\\   |  < __________  //'  //  _)   )/-._`.  (,-')  )  / \\_.    /\\. _____\n"
	"a:f        |  |        .__./    //  '\\  |//    `.\\ '\\ (  (  <`   ._  '\n"
	"           >  |      _.  /   ..-\\ _    _/ \\_.  \\ `\\    \\_ `---.-'__   \n"
	"        . /  `-   _.'        /   `   _/|       J  /`     `-,,-----.`-.\n"
	"            '  .:'          '`      '          < `   f  I //        `�\\_,\n"
	"              '                         \\.     J        I/\\_.        ./\n"
	"         __/                            `:     I  .:    K  `          `\n"
	"         \\/ )                            `,   J         L             \n"
	"          )_(_                             .  F  .-'    J             \n"
	"         /    `.                           .  I  (.   . I _.-.._      \n"
	"   '    <'    \\ )                     _.---.J/      :'   L -'         \n"
	" .:.     \\. _.->/                        _.-'_.)     ` `-.`---.,_.    \n"
	":<        (    \\                    .--\"\"   .F' J) `.`L.__`-.___      \n"
	".:        |-'\\_.|                          Y ..Z     ))   `--'  `-    \n"
	".         ) | > :                            . '    :'                \n"
	"          / ) L_J                            .x,.\n"
	"          L_J .,                             .:<.,  \n"
	"        .'`   `                               :J.,` \n"
	"                                           . ;.+K,:.\n"
	"                                               .,L+.,\n";

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form()
{
	this->setName("ShrubberyCreationForm");
	this->setReqSignGrade(145);
	this->setReqExecuteGrade(137);
	std::cout<<"Called ShrubberyCreationForm(void)"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: Form("Shrubbery", 145, 137)
{
	this->setTarget(target);
	std::cout<<"Called ShrubberyCreationForm(const std::string &type)"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs)
	: Form(rhs)
{
	this->setTarget(rhs.getTarget());
	std::cout<<"Called ShrubberyCreationForm(const ShrubberyCreationForm &rhs)"<<std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout<<"Called ~ShrubberyCreationForm(void)"<<std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		this->Form::operator=(rhs);
		this->setTarget(rhs.getTarget());
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!(this->getIsSigned()))
		throw (ShrubberyCreationForm::NotSignedException());
	if (executor.getGrade() > this->getReqExecuteGrade())
		throw (ShrubberyCreationForm::GradeTooLowException());

	std::ofstream	out_file;

	out_file.open(this->getTarget() + "_shrubbery");
	if (!out_file.is_open())
		throw (ShrubberyCreationForm::FailedOpenFile());
	out_file << ShrubberyCreationForm::_ASCII_TREE;
	out_file.close();
}
