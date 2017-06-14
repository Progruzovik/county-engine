#include <CE/UI/Button.hpp>

namespace ce {

Button::Button(ce::Listener *listener, const sf::String &string, const sf::Vector2f &size)
    : RectangleNode(size.x * ce::Parameters::get().getK(), size.y * ce::Parameters::get().getK(),
                    sf::Color(0x333333FF), true, false, listener),
      text(new Text("", Text::CHRACTER_SIZE, sf::Color::White)), size(size)
{
    setString(string);
    addChild(text);
}

const sf::String &Button::getString() const
{
    return text->getString();
}

void Button::setString(const sf::String &value)
{
    text->setString(value);
    text->setOrigin(text->getCenterX(), text->getCenterY());
    text->setPos(getCenterX(), getCenterY());
}

void Button::setWidth(float value)
{
    setSize(value, size.y);
}

void Button::setHeight(float value)
{
    setSize(size.x, value);
}

void Button::setSize(float width, float height)
{
    size.x = width;
    size.y = height;
    ce::RectangleNode::setSize(width * ce::Parameters::get().getK(), height * ce::Parameters::get().getK());
    text->setPos(getCenterX(), getCenterY());
}

void Button::resize()
{
    ce::RectangleNode::setSize(size.x * ce::Parameters::get().getK(), size.y * ce::Parameters::get().getK());
    text->resize();
    text->setOrigin(text->getCenterX(), text->getCenterY());
}

void Button::onMouseEntered()
{
    setState(State::MOUSE_OVER);
}

void Button::onMouseLeft()
{
    if (checkSelectable()) {
        setState(State::DEFAULT);
    } else {
        setState(State::DISABLED);
    }
}

void Button::onLeftMouseButtonPressed()
{
    setState(State::MOUSE_PRESSED);
}

void Button::onLeftMouseButtonReleased()
{
    setState(State::MOUSE_OVER);
    declareEvent(ce::CLICKED);
}

void Button::setState(State state)
{
    this->state = state;
    if (state == State::DEFAULT) {
        shape.setFillColor(sf::Color(0x333333FF));
    } else if (state == State::MOUSE_OVER || state == State::DISABLED) {
        shape.setFillColor(sf::Color(0x666666FF));
    } else if (state == State::MOUSE_PRESSED) {
        shape.setFillColor(sf::Color::Black);
    }
}

}