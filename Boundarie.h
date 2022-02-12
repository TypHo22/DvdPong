#ifndef BOUNDARIE_H
#define BOUNDARIE_H


class Boundarie
{
public:
    Boundarie();
    void setBoundarie(const float width,const float height);
    bool checkInsideOfBoundarie(const float x,const float y) const;
private:
    float width_;
    float height_;
};

#endif // BOUNDARIE_H
