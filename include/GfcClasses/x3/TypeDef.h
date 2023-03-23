#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <string>
#include <assert.h>

typedef bool GfcBoolean;

typedef double GfcDate;

typedef double GfcDateTime;

typedef double GfcDouble;

typedef std::wstring GfcString;

typedef GfcString GfcElev;

typedef std::wstring GfcIdentity;

typedef int GfcInteger;

typedef GfcString GfcLabel;

typedef GfcString GfcText;

typedef double GfcTime;

enum GfcArcType
{
    AT_LINE,
    AT_ACS,
    AT_CS,
    AT_ACL,
    AT_CL
};

enum GfcBooleanOperator
{
    BO_UNION,
    BO_INTERSECTION,
    BO_DIFFERENCE
};

enum GfcConnectionType
{
    CT_ATPATH,
    CT_ATSTART,
    CT_ATEND,
    CT_NOTDEFINED
};

enum GfcFragTestFunc
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

enum GfcSceneBlendFactor
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

enum GfcSweepType
{
    ST_Perpendicular,
    ST_Upright,
    ST_Facepoint
};

enum GfcTextureType
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

inline std::string GfcArcTypeToString(GfcArcType nValue)
{
    switch(nValue)
    {
    case GfcArcType::AT_LINE:
        return ".AT_LINE.";
        break;
    case GfcArcType::AT_ACS:
        return ".AT_ACS.";
        break;
    case GfcArcType::AT_CS:
        return ".AT_CS.";
        break;
    case GfcArcType::AT_ACL:
        return ".AT_ACL.";
        break;
    case GfcArcType::AT_CL:
        return ".AT_CL.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfcArcType(const std::string& sValue, GfcArcType& nType)
{
    if(sValue.compare(".AT_LINE.") == 0)
    {
        nType = GfcArcType::AT_LINE;
        return true;
    }
    if(sValue.compare(".AT_ACS.") == 0)
    {
        nType = GfcArcType::AT_ACS;
        return true;
    }
    if(sValue.compare(".AT_CS.") == 0)
    {
        nType = GfcArcType::AT_CS;
        return true;
    }
    if(sValue.compare(".AT_ACL.") == 0)
    {
        nType = GfcArcType::AT_ACL;
        return true;
    }
    if(sValue.compare(".AT_CL.") == 0)
    {
        nType = GfcArcType::AT_CL;
        return true;
    }
    return false;
}

inline std::string GfcBooleanOperatorToString(GfcBooleanOperator nValue)
{
    switch(nValue)
    {
    case GfcBooleanOperator::BO_UNION:
        return ".BO_UNION.";
        break;
    case GfcBooleanOperator::BO_INTERSECTION:
        return ".BO_INTERSECTION.";
        break;
    case GfcBooleanOperator::BO_DIFFERENCE:
        return ".BO_DIFFERENCE.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfcBooleanOperator(const std::string& sValue, GfcBooleanOperator& nType)
{
    if(sValue.compare(".BO_UNION.") == 0)
    {
        nType = GfcBooleanOperator::BO_UNION;
        return true;
    }
    if(sValue.compare(".BO_INTERSECTION.") == 0)
    {
        nType = GfcBooleanOperator::BO_INTERSECTION;
        return true;
    }
    if(sValue.compare(".BO_DIFFERENCE.") == 0)
    {
        nType = GfcBooleanOperator::BO_DIFFERENCE;
        return true;
    }
    return false;
}

inline std::string GfcConnectionTypeToString(GfcConnectionType nValue)
{
    switch(nValue)
    {
    case GfcConnectionType::CT_ATPATH:
        return ".CT_ATPATH.";
        break;
    case GfcConnectionType::CT_ATSTART:
        return ".CT_ATSTART.";
        break;
    case GfcConnectionType::CT_ATEND:
        return ".CT_ATEND.";
        break;
    case GfcConnectionType::CT_NOTDEFINED:
        return ".CT_NOTDEFINED.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfcConnectionType(const std::string& sValue, GfcConnectionType& nType)
{
    if(sValue.compare(".CT_ATPATH.") == 0)
    {
        nType = GfcConnectionType::CT_ATPATH;
        return true;
    }
    if(sValue.compare(".CT_ATSTART.") == 0)
    {
        nType = GfcConnectionType::CT_ATSTART;
        return true;
    }
    if(sValue.compare(".CT_ATEND.") == 0)
    {
        nType = GfcConnectionType::CT_ATEND;
        return true;
    }
    if(sValue.compare(".CT_NOTDEFINED.") == 0)
    {
        nType = GfcConnectionType::CT_NOTDEFINED;
        return true;
    }
    return false;
}

inline std::string GfcFragTestFuncToString(GfcFragTestFunc nValue)
{
    switch(nValue)
    {
    case GfcFragTestFunc::FTF_NEVER:
        return ".FTF_NEVER.";
        break;
    case GfcFragTestFunc::FTF_LESS:
        return ".FTF_LESS.";
        break;
    case GfcFragTestFunc::FTF_EQUAL:
        return ".FTF_EQUAL.";
        break;
    case GfcFragTestFunc::FTF_LEQUAL:
        return ".FTF_LEQUAL.";
        break;
    case GfcFragTestFunc::FTF_GREATER:
        return ".FTF_GREATER.";
        break;
    case GfcFragTestFunc::FTF_NOTEQUAL:
        return ".FTF_NOTEQUAL.";
        break;
    case GfcFragTestFunc::FTF_GEQUAL:
        return ".FTF_GEQUAL.";
        break;
    case GfcFragTestFunc::FTF_ALWAYS:
        return ".FTF_ALWAYS.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfcFragTestFunc(const std::string& sValue, GfcFragTestFunc& nType)
{
    if(sValue.compare(".FTF_NEVER.") == 0)
    {
        nType = GfcFragTestFunc::FTF_NEVER;
        return true;
    }
    if(sValue.compare(".FTF_LESS.") == 0)
    {
        nType = GfcFragTestFunc::FTF_LESS;
        return true;
    }
    if(sValue.compare(".FTF_EQUAL.") == 0)
    {
        nType = GfcFragTestFunc::FTF_EQUAL;
        return true;
    }
    if(sValue.compare(".FTF_LEQUAL.") == 0)
    {
        nType = GfcFragTestFunc::FTF_LEQUAL;
        return true;
    }
    if(sValue.compare(".FTF_GREATER.") == 0)
    {
        nType = GfcFragTestFunc::FTF_GREATER;
        return true;
    }
    if(sValue.compare(".FTF_NOTEQUAL.") == 0)
    {
        nType = GfcFragTestFunc::FTF_NOTEQUAL;
        return true;
    }
    if(sValue.compare(".FTF_GEQUAL.") == 0)
    {
        nType = GfcFragTestFunc::FTF_GEQUAL;
        return true;
    }
    if(sValue.compare(".FTF_ALWAYS.") == 0)
    {
        nType = GfcFragTestFunc::FTF_ALWAYS;
        return true;
    }
    return false;
}

inline std::string GfcSceneBlendFactorToString(GfcSceneBlendFactor nValue)
{
    switch(nValue)
    {
    case GfcSceneBlendFactor::SBF_DST_ALPHA:
        return ".SBF_DST_ALPHA.";
        break;
    case GfcSceneBlendFactor::SBF_DST_COLOR:
        return ".SBF_DST_COLOR.";
        break;
    case GfcSceneBlendFactor::SBF_ONE:
        return ".SBF_ONE.";
        break;
    case GfcSceneBlendFactor::SBF_ONE_MINUS_DST_COLOR:
        return ".SBF_ONE_MINUS_DST_COLOR.";
        break;
    case GfcSceneBlendFactor::SBF_ONE_MINUS_DST_ALPHA:
        return ".SBF_ONE_MINUS_DST_ALPHA.";
        break;
    case GfcSceneBlendFactor::SBF_ONE_MINUS_SRC_ALPHA:
        return ".SBF_ONE_MINUS_SRC_ALPHA.";
        break;
    case GfcSceneBlendFactor::SBF_ONE_MINUS_SRC_COLOR:
        return ".SBF_ONE_MINUS_SRC_COLOR.";
        break;
    case GfcSceneBlendFactor::SBF_SRC_ALPHA:
        return ".SBF_SRC_ALPHA.";
        break;
    case GfcSceneBlendFactor::SBF_SRC_ALPHA_SATURATE:
        return ".SBF_SRC_ALPHA_SATURATE.";
        break;
    case GfcSceneBlendFactor::SBF_SRC_COLOR:
        return ".SBF_SRC_COLOR.";
        break;
    case GfcSceneBlendFactor::SBF_ZERO:
        return ".SBF_ZERO.";
        break;
    case GfcSceneBlendFactor::SBF_CONSTANT_COLOR:
        return ".SBF_CONSTANT_COLOR.";
        break;
    case GfcSceneBlendFactor::SBF_ONE_MINUS_CONSTANT_COLOR:
        return ".SBF_ONE_MINUS_CONSTANT_COLOR.";
        break;
    case GfcSceneBlendFactor::SBF_CONSTANT_ALPHA:
        return ".SBF_CONSTANT_ALPHA.";
        break;
    case GfcSceneBlendFactor::SBF_ONE_MINUS_CONSTANT_ALPHA:
        return ".SBF_ONE_MINUS_CONSTANT_ALPHA.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfcSceneBlendFactor(const std::string& sValue, GfcSceneBlendFactor& nType)
{
    if(sValue.compare(".SBF_DST_ALPHA.") == 0)
    {
        nType = GfcSceneBlendFactor::SBF_DST_ALPHA;
        return true;
    }
    if(sValue.compare(".SBF_DST_COLOR.") == 0)
    {
        nType = GfcSceneBlendFactor::SBF_DST_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_ONE.") == 0)
    {
        nType = GfcSceneBlendFactor::SBF_ONE;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_DST_COLOR.") == 0)
    {
        nType = GfcSceneBlendFactor::SBF_ONE_MINUS_DST_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_DST_ALPHA.") == 0)
    {
        nType = GfcSceneBlendFactor::SBF_ONE_MINUS_DST_ALPHA;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_SRC_ALPHA.") == 0)
    {
        nType = GfcSceneBlendFactor::SBF_ONE_MINUS_SRC_ALPHA;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_SRC_COLOR.") == 0)
    {
        nType = GfcSceneBlendFactor::SBF_ONE_MINUS_SRC_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_SRC_ALPHA.") == 0)
    {
        nType = GfcSceneBlendFactor::SBF_SRC_ALPHA;
        return true;
    }
    if(sValue.compare(".SBF_SRC_ALPHA_SATURATE.") == 0)
    {
        nType = GfcSceneBlendFactor::SBF_SRC_ALPHA_SATURATE;
        return true;
    }
    if(sValue.compare(".SBF_SRC_COLOR.") == 0)
    {
        nType = GfcSceneBlendFactor::SBF_SRC_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_ZERO.") == 0)
    {
        nType = GfcSceneBlendFactor::SBF_ZERO;
        return true;
    }
    if(sValue.compare(".SBF_CONSTANT_COLOR.") == 0)
    {
        nType = GfcSceneBlendFactor::SBF_CONSTANT_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_CONSTANT_COLOR.") == 0)
    {
        nType = GfcSceneBlendFactor::SBF_ONE_MINUS_CONSTANT_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_CONSTANT_ALPHA.") == 0)
    {
        nType = GfcSceneBlendFactor::SBF_CONSTANT_ALPHA;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_CONSTANT_ALPHA.") == 0)
    {
        nType = GfcSceneBlendFactor::SBF_ONE_MINUS_CONSTANT_ALPHA;
        return true;
    }
    return false;
}

inline std::string GfcSweepTypeToString(GfcSweepType nValue)
{
    switch(nValue)
    {
    case GfcSweepType::ST_Perpendicular:
        return ".ST_Perpendicular.";
        break;
    case GfcSweepType::ST_Upright:
        return ".ST_Upright.";
        break;
    case GfcSweepType::ST_Facepoint:
        return ".ST_Facepoint.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfcSweepType(const std::string& sValue, GfcSweepType& nType)
{
    if(sValue.compare(".ST_Perpendicular.") == 0)
    {
        nType = GfcSweepType::ST_Perpendicular;
        return true;
    }
    if(sValue.compare(".ST_Upright.") == 0)
    {
        nType = GfcSweepType::ST_Upright;
        return true;
    }
    if(sValue.compare(".ST_Facepoint.") == 0)
    {
        nType = GfcSweepType::ST_Facepoint;
        return true;
    }
    return false;
}

inline std::string GfcTextureTypeToString(GfcTextureType nValue)
{
    switch(nValue)
    {
    case GfcTextureType::TT_UNKNOW:
        return ".TT_UNKNOW.";
        break;
    case GfcTextureType::TT_DIFFUSE:
        return ".TT_DIFFUSE.";
        break;
    case GfcTextureType::TT_BUMP:
        return ".TT_BUMP.";
        break;
    case GfcTextureType::TT_SPECULAR:
        return ".TT_SPECULAR.";
        break;
    case GfcTextureType::TT_ALPHA:
        return ".TT_ALPHA.";
        break;
    case GfcTextureType::TT_EMISSIVE:
        return ".TT_EMISSIVE.";
        break;
    case GfcTextureType::TT_RELIEF:
        return ".TT_RELIEF.";
        break;
    case GfcTextureType::TT_ENVIRONMENT:
        return ".TT_ENVIRONMENT.";
        break;
    case GfcTextureType::TT_LIGHT:
        return ".TT_LIGHT.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfcTextureType(const std::string& sValue, GfcTextureType& nType)
{
    if(sValue.compare(".TT_UNKNOW.") == 0)
    {
        nType = GfcTextureType::TT_UNKNOW;
        return true;
    }
    if(sValue.compare(".TT_DIFFUSE.") == 0)
    {
        nType = GfcTextureType::TT_DIFFUSE;
        return true;
    }
    if(sValue.compare(".TT_BUMP.") == 0)
    {
        nType = GfcTextureType::TT_BUMP;
        return true;
    }
    if(sValue.compare(".TT_SPECULAR.") == 0)
    {
        nType = GfcTextureType::TT_SPECULAR;
        return true;
    }
    if(sValue.compare(".TT_ALPHA.") == 0)
    {
        nType = GfcTextureType::TT_ALPHA;
        return true;
    }
    if(sValue.compare(".TT_EMISSIVE.") == 0)
    {
        nType = GfcTextureType::TT_EMISSIVE;
        return true;
    }
    if(sValue.compare(".TT_RELIEF.") == 0)
    {
        nType = GfcTextureType::TT_RELIEF;
        return true;
    }
    if(sValue.compare(".TT_ENVIRONMENT.") == 0)
    {
        nType = GfcTextureType::TT_ENVIRONMENT;
        return true;
    }
    if(sValue.compare(".TT_LIGHT.") == 0)
    {
        nType = GfcTextureType::TT_LIGHT;
        return true;
    }
    return false;
}

#endif
