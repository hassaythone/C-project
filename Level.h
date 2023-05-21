#ifndef LEVEL_H
#define LEVEL_H

class Level {
public:
    Level();
    void increment();
    int getScoreThreshold() const;
    void reset();
private:
    int m_level;
};

#endif // LEVEL_H