class Spreadsheet {
public:

    unordered_map<string, int> sheet;

    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {

        sheet[cell] = value;
        
    }
    
    void resetCell(string cell) {

        sheet[cell] = 0;

    }
    
    int parse(string operand) {
        if (!isdigit(operand[0]))
            return sheet[operand];
        else
            return stoi(operand);
    }


    int getValue(string formula) {

        int i = 0;
        for (;i < formula.size(); i++) {
            if (formula[i] == '+')
                break;
        }

        // =A1+6
        // i = 3
        // i - 1 ~ 1 so the length is i-1 - 1 + 1
        // n-1 ~ i + 1 so the length n-1 - (i+1) + 1
        string firstOperand = formula.substr(1, i - 1 - 1 + 1);
        string secondOperand = formula.substr(i+1, formula.size()-1 - (i+1) + 1);
        int firstNumber = parse(firstOperand);
        int secondNumber = parse(secondOperand);
        return firstNumber + secondNumber;
    }   
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */