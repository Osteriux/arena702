#include "animationLine.h"

AnimationLine::AnimationLine(const char* texturePath, int nbImages, sf::IntRect rect, float switchTime, sf::Vector2f position, sf::Vector2f scale)
    : Animation(texturePath, rect, switchTime, position, scale)
{
    this->nbImages = nbImages;
    currentImage = 0;
}

bool AnimationLine::update(float dt)
{
    currentTime += dt;
    if(currentTime >= switchTime)
    {
        currentTime -= switchTime;
        currentImage++;
        if(currentImage <= nbImages)
        {
            rect.left = currentImage * rect.width;
            setTextureRect(rect);
        }
    }
    return currentImage >= nbImages;
}