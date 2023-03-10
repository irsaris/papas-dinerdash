#include "BaseCounter.h"
#include "Animation.h"

class StoveCounter: public BaseCounter{
    private:
        Item *item;

    public:
        StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite);
        virtual Item* getItem();
        virtual void showItem();
        void tick();
	    void render();

        //added variables
        Animation *loadingBar;
		ofImage temp;
        int counter = 0;
        bool isCooking = false;

};