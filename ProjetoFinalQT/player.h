#ifndef PLAYER_H_
#define PLAYER_H_

class Player
{
    public:
        void addPoints();
        int getPoints();
        int getId();
        void setId(int i);
        void setCard(int i);
        int getCard();
        bool getAnswer();
        void setAnswer(bool res);
    private:
        int points = 0;
        int id;
        int card;
        bool result;
};

#endif
