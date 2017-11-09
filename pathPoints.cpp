//
// Created by BearMace on 06/11/2017.
//

#include "pathPoints.h"

void pathPoints::initTargetPoints()
{
    //this creates the path-Points {x,y}:
    Cordinates tmp0={100,100};
    Cordinates tmp1={800,100};
    Cordinates tmp2={100,500};
    Cordinates tmp3={540,750};
    Cordinates tmp4={470,500};
    Cordinates tmp5={600,800};
    Cordinates tmp6={1100,750};
    Cordinates tmp7={900,800};
    Cordinates tmp8={100,400};
    //to be continued.....

    //now we create the map:
    targetPoints[0]=tmp0;
    targetPoints[1]=tmp1;
    targetPoints[2]=tmp2;
    targetPoints[3]=tmp3;
    targetPoints[4]=tmp4;
    targetPoints[5]=tmp5;
    targetPoints[6]=tmp6;
    targetPoints[7]=tmp7;
    targetPoints[8]=tmp8;
}
