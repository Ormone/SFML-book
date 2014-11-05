#ifndef GAME_HPP
#define GAME_HPP

#include <memory>

#include <SFML/Window.hpp>
#include <SFML-Book/Board.hpp>
#include <SFML-Book/Stats.hpp>

namespace book
{
    class Game
    {
        public:
            //not capyable class
            Game(const Game&) = delete;
            Game& operator=(const Game&) = delete;

            Game(); //< constuctor

            void run(); //< run the game

        private:

            void processEvents();//< Process events
            void update(sf::Time deltaTime); //< do some updates
            void render();//< draw all the stuff

            void newPiece();

            sf::RenderWindow _window; //< the window use to display the game
            std::unique_ptr<Piece> _current_piece; //< the current piece
            Board _board; //< the game board
            Stats _stats; //< stats printer

    };
}
#endif