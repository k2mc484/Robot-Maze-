#ifndef SENSORS_H
#define SENSORS_H
class Sensors{
public:
    bool lineToLeft() const {return bToL;}
    bool lineAhead() const {return bInF;}
    bool lineToRight() const {return bToR;}
    bool atEnd() const {return at_end;}

    void setLeft(int l) {bToL=l;}
    void setRight(int l) {bToR=l;}
    void setAhead (int l) {bInF = l;}
    void setAtEnd (int l) {at_end = l;}
private:
    int bToL;
    int bInF;
    int bToR;
    int at_end;
};
#endif // SENSORS_H
