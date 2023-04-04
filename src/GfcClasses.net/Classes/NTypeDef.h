#ifndef NTYPEDEF_H
#define NTYPEDEF_H

typedef bool NGfcBoolean;

typedef double NGfcDate;

typedef double NGfcDateTime;

typedef double NGfcDouble;

typedef System::String^ NGfcString;

typedef NGfcString NGfcElev;

typedef System::String^ NGfcIdentity;

typedef int NGfcInteger;

typedef NGfcString NGfcLabel;

typedef NGfcString NGfcText;

typedef double NGfcTime;

public enum class NGfcArcType
{
    AT_LINE,
    AT_ACS,
    AT_CS,
    AT_ACL,
    AT_CL
};

public enum class NGfcBooleanOperator
{
    BO_UNION,
    BO_INTERSECTION,
    BO_DIFFERENCE
};

public enum class NGfcConnectionType
{
    CT_ATPATH,
    CT_ATSTART,
    CT_ATEND,
    CT_NOTDEFINED
};

public enum class NGfcFragTestFunc
{
    FTF_NEVER,
    FTF_LESS,
    FTF_EQUAL,
    FTF_LEQUAL,
    FTF_GREATER,
    FTF_NOTEQUAL,
    FTF_GEQUAL,
    FTF_ALWAYS
};

public enum class NGfcSceneBlendFactor
{
    SBF_DST_ALPHA,
    SBF_DST_COLOR,
    SBF_ONE,
    SBF_ONE_MINUS_DST_COLOR,
    SBF_ONE_MINUS_DST_ALPHA,
    SBF_ONE_MINUS_SRC_ALPHA,
    SBF_ONE_MINUS_SRC_COLOR,
    SBF_SRC_ALPHA,
    SBF_SRC_ALPHA_SATURATE,
    SBF_SRC_COLOR,
    SBF_ZERO,
    SBF_CONSTANT_COLOR,
    SBF_ONE_MINUS_CONSTANT_COLOR,
    SBF_CONSTANT_ALPHA,
    SBF_ONE_MINUS_CONSTANT_ALPHA
};

public enum class NGfcSweepType
{
    ST_Perpendicular,
    ST_Upright,
    ST_Facepoint
};

public enum class NGfcTextureType
{
    TT_UNKNOW,
    TT_DIFFUSE,
    TT_BUMP,
    TT_SPECULAR,
    TT_ALPHA,
    TT_EMISSIVE,
    TT_RELIEF,
    TT_ENVIRONMENT,
    TT_LIGHT
};

#endif
