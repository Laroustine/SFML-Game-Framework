#include <iostream>
#include "States/StatePlaying.hpp"
#include "GUI/Button.hpp"
#include "GUI/Canvas.hpp"
#include "GUI/Textbox.hpp"
#include "Game.hpp"

StatePlaying::StatePlaying(Game& game)
:   StateBase(game)
,   m_TestMenu({1280 / 2, 60})
{
    std::unique_ptr<gui::Button> b = gui::makeButton();
    std::unique_ptr<gui::Canvas> c = gui::makeCanvas(gui::WidgetSize::Huge512);
    std::unique_ptr<gui::TextBox> d = gui::makeTextBox();

    b->setText("Button 1");
    b->setTexture(ResourceHolder::get().textures.get("a_man"));
    b->setFunction([]() {
        std::cout << "Button 1 has been clicked!" << '\n';
    });

    c->setTexture(ResourceHolder::get().textures.get("a_man")) ;
    c->setSize({350, 350});

    d->setTitle("Enter Text:");

    m_TestMenu.setTitle("This is a Menu");
    m_TestMenu.addWidget(std::move(c));
    m_TestMenu.addWidget(std::move(d));
    m_TestMenu.addWidget(std::move(b));
}

void StatePlaying::handleEvent(sf::Event e)
{
    m_TestMenu.handleEvent(e, m_pGame->getWindow());
}

void StatePlaying::handleInput()
{

}

void StatePlaying::update(sf::Time deltaTime)
{
    (void)deltaTime;
}

void StatePlaying::fixedUpdate(sf::Time deltaTime)
{
    (void)deltaTime;
}

void StatePlaying::render(sf::RenderTarget& renderer)
{
    m_TestMenu.render(renderer);
}
