
#include "MainLayer.h"

void MainLayer::onAttach()
{
    std::cout << "Attach";
}

void MainLayer::onDetach()
{
    std::cout << "Detach";
}

void MainLayer::onEvent(Event &event)
{
    std::cout << "EVENTO";
}

void MainLayer::onUpdate()
{

}
