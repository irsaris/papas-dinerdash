#include "State.h"
#include "Restaurant.h"
#include "Client.h"
#include "Button.h"

class WinState : public State {
	private:
        Button *restartButton;
    public:
	    WinState();
	    void tick();
	    void render();
	    void keyPressed(int key);
	    void mousePressed(int x, int y, int button);
	    void reset();
        void keyReleased(int key);
		
		//added variables
		Animation *menuStateBackground;
		ofImage temp;
};
