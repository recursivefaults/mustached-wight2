#ifndef GAME_STATE_MANAGER_H
#define GAME_STATE_MANAGER_H

#include <stack>
#include "Graphics.h"
#include "SoundEngine.h"
#include "TextureManager.h"
#include "FontManager.h"
#include "GameState.h"

class GameState;

class GameStateManager
{
    public:
        GameStateManager(Graphics *g, SoundEngine *s, TextureManager *t, FontManager *f) : _graphics(g), _sound(s), _textures(t), _fonts(f), running(true) {};
        ~GameStateManager();
        /**
         * Pause the current state and put new state in focus.
         * Example: From main menu to the game or bringing up an in game menu.
         **/
        void pushState(GameState *);
        /**
         * Destroy the current state and swap it for a new one entirely.
         */
        void changeState(GameState *);
        /**
         * Destroy the current state and resume the one before it.
         **/
        void popState();
        void cleanUp();
        void handleInput();
        void update(int);
        void render();
        bool isRunning() {return running;};


        TextureManager *getTextureManager() const {return _textures;};
        SoundEngine *getSoundEngine() const {return _sound;};
        FontManager *getFontManager() const {return _fonts;};
        Graphics *getGraphics() const {return _graphics;};

    protected:
    private:
        Graphics *_graphics;
        SoundEngine *_sound;
        TextureManager *_textures;
        FontManager *_fonts;
        bool running;
        std::stack<GameState *> stateStack;
};

#endif
