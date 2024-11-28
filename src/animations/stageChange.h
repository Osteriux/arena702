#pragma once
#include "onomatope.h"

class StageChange : public Onomatope
{
public:
    /// @brief Constructeur de StageChange
    /// @param stage numéro du stage
    StageChange(int stage);

    bool update(float dt) override;

    /// @brief ~StageChange est le destructeur par default de StageChange
    ~StageChange() = default;

private:
    std::string toRoman(int n);
};
