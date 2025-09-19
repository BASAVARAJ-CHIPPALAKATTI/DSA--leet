//easy
class Spreadsheet {
public:
    vector<vector<int>>sheet;
    Spreadsheet(int rows) {
        sheet.assign(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        //ex cell=A1
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1))-1;
        sheet[row][col]=value;
    }
    
    void resetCell(string cell) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1))-1;

        sheet[row][col]=0;
    }
    
    int getValue(string formula) {
        //=x+y
        string s=formula.substr(1);
        int idx=s.find('+');
        string left=s.substr(0,idx);
        string right=s.substr(idx+1);

        return solve(left)+solve(right);
    }
    int solve(string c){
        if(isdigit(c[0])){
            return stoi(c);
        }
        int col=c[0]-'A';
        int row=stoi(c.substr(1))-1;

        return sheet[row][col];
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */