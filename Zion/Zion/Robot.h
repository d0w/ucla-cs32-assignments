#ifndef ZION_ROBOT_H
#define ZION_ROBOT_H

class Arena;

class Robot
{
public:
    // Constructor
    Robot(Arena* ap, int r, int c);

    // Accessors
    int  row() const;
    int  col() const;

    // Mutators
    void move();
    bool takeDamageAndLive();

private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_health;
};

#endif