#include "State.h"
#include "Restaurant.h"
#include "Client.h"
#include "Button.h"

class LoseState : public State {
    public:
	    LoseState();
	    void tick();
	    void render();
	    void keyPressed(int key);
	    void mousePressed(int x, int y, int button);
	    void reset();
        void keyReleased(int key);
		ofImage original, yes, no;
		bool isYes = false;
		
    private:
        Button *restartButton;
};