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

enum GfcGeometryDataType
{
    GDT_UNCOMPRESS,
    GDT_COMPRESS,
    GDT_UNKNOWN
};

enum GfcPrimitiveType
{
    GPT_POINTS,
    GPT_LINES,
    GPT_LINE_STRIP,
    GPT_TRIANGLES,
    GPT_TRIANGLE_STRIP,
    GPT_TRIANGLE_FAN,
    GPT_UNKNOWN
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

inline std::string GfcGeometryDataTypeToString(GfcGeometryDataType nValue)
{
    switch(nValue)
    {
    case GfcGeometryDataType::GDT_UNCOMPRESS:
        return ".GDT_UNCOMPRESS.";
        break;
    case GfcGeometryDataType::GDT_COMPRESS:
        return ".GDT_COMPRESS.";
        break;
    case GfcGeometryDataType::GDT_UNKNOWN:
        return ".GDT_UNKNOWN.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfcGeometryDataType(const std::string& sValue, GfcGeometryDataType& nType)
{
    if(sValue.compare(".GDT_UNCOMPRESS.") == 0)
    {
        nType = GfcGeometryDataType::GDT_UNCOMPRESS;
        return true;
    }
    if(sValue.compare(".GDT_COMPRESS.") == 0)
    {
        nType = GfcGeometryDataType::GDT_COMPRESS;
        return true;
    }
    if(sValue.compare(".GDT_UNKNOWN.") == 0)
    {
        nType = GfcGeometryDataType::GDT_UNKNOWN;
        return true;
    }
    return false;
}

inline std::string GfcPrimitiveTypeToString(GfcPrimitiveType nValue)
{
    switch(nValue)
    {
    case GfcPrimitiveType::GPT_POINTS:
        return ".GPT_POINTS.";
        break;
    case GfcPrimitiveType::GPT_LINES:
        return ".GPT_LINES.";
        break;
    case GfcPrimitiveType::GPT_LINE_STRIP:
        return ".GPT_LINE_STRIP.";
        break;
    case GfcPrimitiveType::GPT_TRIANGLES:
        return ".GPT_TRIANGLES.";
        break;
    case GfcPrimitiveType::GPT_TRIANGLE_STRIP:
        return ".GPT_TRIANGLE_STRIP.";
        break;
    case GfcPrimitiveType::GPT_TRIANGLE_FAN:
        return ".GPT_TRIANGLE_FAN.";
        break;
    case GfcPrimitiveType::GPT_UNKNOWN:
        return ".GPT_UNKNOWN.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfcPrimitiveType(const std::string& sValue, GfcPrimitiveType& nType)
{
    if(sValue.compare(".GPT_POINTS.") == 0)
    {
        nType = GfcPrimitiveType::GPT_POINTS;
        return true;
    }
    if(sValue.compare(".GPT_LINES.") == 0)
    {
        nType = GfcPrimitiveType::GPT_LINES;
        return true;
    }
    if(sValue.compare(".GPT_LINE_STRIP.") == 0)
    {
        nType = GfcPrimitiveType::GPT_LINE_STRIP;
        return true;
    }
    if(sValue.compare(".GPT_TRIANGLES.") == 0)
    {
        nType = GfcPrimitiveType::GPT_TRIANGLES;
        return true;
    }
    if(sValue.compare(".GPT_TRIANGLE_STRIP.") == 0)
    {
        nType = GfcPrimitiveType::GPT_TRIANGLE_STRIP;
        return true;
    }
    if(sValue.compare(".GPT_TRIANGLE_FAN.") == 0)
    {
        nType = GfcPrimitiveType::GPT_TRIANGLE_FAN;
        return true;
    }
    if(sValue.compare(".GPT_UNKNOWN.") == 0)
    {
        nType = GfcPrimitiveType::GPT_UNKNOWN;
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

#endif
