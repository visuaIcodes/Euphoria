#include "Sprite.hpp"
using namespace Euphoria;
using namespace Rendering;

Sprite::Sprite(std::shared_ptr<sf::Sprite> sprite, std::shared_ptr<sf::Texture> texture) : m_Sprite(std::move(sprite)), m_Texture(std::move(texture)) {}
Sprite::~Sprite() {}
const sf::Drawable& Sprite::GetDrawable() const { return *m_Sprite; }

std::shared_ptr<Sprite> Sprite::CreateSprite(
    const std::string& path,
    const sf::IntRect& rect,
    const sf::Vector2f& pos
) {
    auto texture = std::make_shared<sf::Texture>();
    if (!texture->loadFromFile(path)) return nullptr;

    auto sprite = std::make_shared<sf::Sprite>(*texture, rect);
    sprite->setPosition(pos);

    return std::make_shared<Sprite>(sprite, texture);
}