#include "calculatorTab.hpp"

// Code taken and modified from the borealis example

template < typename Type > std::string to_str (const Type & t) {
  std::ostringstream os;
  os << t;
  return os.str();
}

CalculatorTab::CalculatorTab() {
    this->inflateFromXMLRes("xml/tabs/calculator.xml");

    BRLS_REGISTER_CLICK_BY_ID("button_add", this->onAdditionButtonClicked);
    BRLS_REGISTER_CLICK_BY_ID("button_subtract", this->onSubtractButtonClicked);
    BRLS_REGISTER_CLICK_BY_ID("button_mutiply", this->onMultiplyButtonClicked);
    BRLS_REGISTER_CLICK_BY_ID("button_divide", this->onDivideButtonClicked);
    BRLS_REGISTER_CLICK_BY_ID("cal_screen", this->onScreenButtonClicked);
}

CalculatorTab::~CalculatorTab() {
    brls::Logger::debug("CalculatorTab struct destroyed");
}

bool CalculatorTab::onAdditionButtonClicked(brls::View* view) {
    brls::Logger::debug("Addition button clicked");

    operation = "+";
    return true;
}

bool CalculatorTab::onSubtractButtonClicked(brls::View* view) {
    brls::Logger::debug("Subtraction button clicked");

    operation = "-";
    return true;
}

bool CalculatorTab::onMultiplyButtonClicked(brls::View* view) {
    brls::Logger::debug("Multiply button clicked");

    operation = "*";
    return true;
}

bool CalculatorTab::onDivideButtonClicked(brls::View* view) {
    brls::Logger::debug("Divide button clicked");

    operation = "/";
    return true;
}

bool CalculatorTab::onScreenButtonClicked(brls::View* view) {
        brls::Logger::debug("Screen button clicked");

        brls::Logger::info("Operation is set as: " + operation);

        std::vector<float> vec;

        char tmpoutstr[32] = {0};
        #ifdef __SWITCH__
        SwkbdConfig kbd;
        Result rc = swkbdCreate(&kbd, 0);

        if (R_SUCCEEDED(rc)) {
            swkbdConfigMakePresetDefault(&kbd);
            swkbdConfigSetGuideText(&kbd, "Enter all numbers with a space in-between: ");

            rc = swkbdShow(&kbd, tmpoutstr, sizeof(tmpoutstr));

            swkbdClose(&kbd);
        }
        #else

        std::cout << "Enter all numbers with a space in-between: " << std::endl;
        std::cin.getline(tmpoutstr, 32);

        #endif

        std::istringstream iss(tmpoutstr);
        std::string Num;

        while (iss >> Num) {
            vec.emplace_back(std::stof(Num));
        }
        
        float answer = Calculator::solve(vec, operation);

        //std::cout << "The answer is: " << answer << std::endl;

        this->cal_button_label->setText("The answer is " + to_str(answer));

        return true;
}

brls::View* CalculatorTab::create() {
    return new CalculatorTab();
}