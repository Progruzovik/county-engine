#ifndef CE_ACT_HPP
#define CE_ACT_HPP

#include <CE/Core/RootNode.hpp>
#include <CE/Event/Speaker.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace ce {

enum class ContentMode { STATIC, MOVABLE_BY_MOUSE, CENTERED_ON_NODE };

class Act : public Speaker, public Listener
{
public:
    Act(Stage *stage, ContentMode contentMode, const sf::Color &bgColor = sf::Color::Black);

    void onLeftMouseButtonPressed();
    void onLeftMouseButtonReleased();
    void onRightMouseButtonPressed();
    void onRightMouseButtonReleased();
    virtual void onKeyReleased(sf::Keyboard::Key key) {}
    void onEvent(ce::Speaker *speaker, const sf::String &name) override {}

    const sf::Color &getBgColor() const;
    void setCenter(AbstractNode *value);
    void setContent(AbstractNode *value);
    void setLeftUi(AbstractNode *value);
    void setRightUi(AbstractNode *value);
    void setTopUi(AbstractNode *value);
    void setBottomUi(AbstractNode *value);

    void removeContent(bool toDelete = false);

    virtual void setUpNodes();
    void update();

protected:
    sf::Color bgColor;
    RootNode root;

    virtual void resizeUi() {}

private:
    static constexpr unsigned int SCROLL_SPEED = 5;

    ContentMode contentMode;
    bool isRightMouseButtonPressed = false;
    bool isMouseMovedWithRightButton = false;
    sf::Vector2u mousePosition;

    AbstractNode *center = nullptr;
    AbstractNode *content = nullptr;
    AbstractNode *leftUi = nullptr;
    AbstractNode *rightUi = nullptr;
    AbstractNode *topUi = nullptr;
    AbstractNode *bottomUi = nullptr;

    void updateUi(AbstractNode *oldUi, AbstractNode *newUi);
};

}

#endif
