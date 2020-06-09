#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <string>
#include "Gfc2String.h"

typedef bool Gfc2Boolean;

typedef double Gfc2Date;

typedef double Gfc2DateTime;

typedef double Gfc2Double;

typedef Gfc2String Gfc2Elev;

typedef std::wstring Gfc2Identity;

typedef int Gfc2Integer;

typedef Gfc2String Gfc2Label;

typedef Gfc2String Gfc2Text;

typedef double Gfc2Time;

enum Gfc2ArcType
{
    AT_LINE,
    AT_ACS,
    AT_CS,
    AT_ACL,
    AT_CL
};

enum Gfc2BooleanOperator
{
    BO_UNION,
    BO_INTERSECTION,
    BO_DIFFERENCE
};

enum Gfc2ConnectionType
{
    CT_ATPATH,
    CT_ATSTART,
    CT_ATEND,
    CT_NOTDEFINED
};

enum Gfc2FragTestFunc
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

enum Gfc2GeometryDataType
{
    GDT_UNCOMPRESS,
    GDT_COMPRESS,
    GDT_UNKNOWN
};

enum Gfc2PrimitiveType
{
    PT_POINTS,
    PT_LINES,
    PT_LINE_STRIP,
    PT_TRIANGLES,
    PT_TRIANGLE_STRIP,
    PT_TRIANGLE_FAN,
    PT_UNKNOWN
};

enum Gfc2SceneBlendFactor
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

enum Gfc2SweepType
{
    ST_Perpendicular,
    ST_Upright,
    ST_Facepoint
};

inline std::string Gfc2ArcTypeToString(Gfc2ArcType nValue)
{
    switch(nValue)
    {
    case Gfc2ArcType::AT_LINE:
        return ".AT_LINE.";
        break;
    case Gfc2ArcType::AT_ACS:
        return ".AT_ACS.";
        break;
    case Gfc2ArcType::AT_CS:
        return ".AT_CS.";
        break;
    case Gfc2ArcType::AT_ACL:
        return ".AT_ACL.";
        break;
    case Gfc2ArcType::AT_CL:
        return ".AT_CL.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfc2ArcType(const std::string& sValue, Gfc2ArcType& nType)
{
    if(sValue.compare(".AT_LINE.") == 0)
    {
        nType = Gfc2ArcType::AT_LINE;
        return true;
    }
    if(sValue.compare(".AT_ACS.") == 0)
    {
        nType = Gfc2ArcType::AT_ACS;
        return true;
    }
    if(sValue.compare(".AT_CS.") == 0)
    {
        nType = Gfc2ArcType::AT_CS;
        return true;
    }
    if(sValue.compare(".AT_ACL.") == 0)
    {
        nType = Gfc2ArcType::AT_ACL;
        return true;
    }
    if(sValue.compare(".AT_CL.") == 0)
    {
        nType = Gfc2ArcType::AT_CL;
        return true;
    }
    return false;
}

inline std::string Gfc2BooleanOperatorToString(Gfc2BooleanOperator nValue)
{
    switch(nValue)
    {
    case Gfc2BooleanOperator::BO_UNION:
        return ".BO_UNION.";
        break;
    case Gfc2BooleanOperator::BO_INTERSECTION:
        return ".BO_INTERSECTION.";
        break;
    case Gfc2BooleanOperator::BO_DIFFERENCE:
        return ".BO_DIFFERENCE.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfc2BooleanOperator(const std::string& sValue, Gfc2BooleanOperator& nType)
{
    if(sValue.compare(".BO_UNION.") == 0)
    {
        nType = Gfc2BooleanOperator::BO_UNION;
        return true;
    }
    if(sValue.compare(".BO_INTERSECTION.") == 0)
    {
        nType = Gfc2BooleanOperator::BO_INTERSECTION;
        return true;
    }
    if(sValue.compare(".BO_DIFFERENCE.") == 0)
    {
        nType = Gfc2BooleanOperator::BO_DIFFERENCE;
        return true;
    }
    return false;
}

inline std::string Gfc2ConnectionTypeToString(Gfc2ConnectionType nValue)
{
    switch(nValue)
    {
    case Gfc2ConnectionType::CT_ATPATH:
        return ".CT_ATPATH.";
        break;
    case Gfc2ConnectionType::CT_ATSTART:
        return ".CT_ATSTART.";
        break;
    case Gfc2ConnectionType::CT_ATEND:
        return ".CT_ATEND.";
        break;
    case Gfc2ConnectionType::CT_NOTDEFINED:
        return ".CT_NOTDEFINED.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfc2ConnectionType(const std::string& sValue, Gfc2ConnectionType& nType)
{
    if(sValue.compare(".CT_ATPATH.") == 0)
    {
        nType = Gfc2ConnectionType::CT_ATPATH;
        return true;
    }
    if(sValue.compare(".CT_ATSTART.") == 0)
    {
        nType = Gfc2ConnectionType::CT_ATSTART;
        return true;
    }
    if(sValue.compare(".CT_ATEND.") == 0)
    {
        nType = Gfc2ConnectionType::CT_ATEND;
        return true;
    }
    if(sValue.compare(".CT_NOTDEFINED.") == 0)
    {
        nType = Gfc2ConnectionType::CT_NOTDEFINED;
        return true;
    }
    return false;
}

inline std::string Gfc2FragTestFuncToString(Gfc2FragTestFunc nValue)
{
    switch(nValue)
    {
    case Gfc2FragTestFunc::FTF_NEVER:
        return ".FTF_NEVER.";
        break;
    case Gfc2FragTestFunc::FTF_LESS:
        return ".FTF_LESS.";
        break;
    case Gfc2FragTestFunc::FTF_EQUAL:
        return ".FTF_EQUAL.";
        break;
    case Gfc2FragTestFunc::FTF_LEQUAL:
        return ".FTF_LEQUAL.";
        break;
    case Gfc2FragTestFunc::FTF_GREATER:
        return ".FTF_GREATER.";
        break;
    case Gfc2FragTestFunc::FTF_NOTEQUAL:
        return ".FTF_NOTEQUAL.";
        break;
    case Gfc2FragTestFunc::FTF_GEQUAL:
        return ".FTF_GEQUAL.";
        break;
    case Gfc2FragTestFunc::FTF_ALWAYS:
        return ".FTF_ALWAYS.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfc2FragTestFunc(const std::string& sValue, Gfc2FragTestFunc& nType)
{
    if(sValue.compare(".FTF_NEVER.") == 0)
    {
        nType = Gfc2FragTestFunc::FTF_NEVER;
        return true;
    }
    if(sValue.compare(".FTF_LESS.") == 0)
    {
        nType = Gfc2FragTestFunc::FTF_LESS;
        return true;
    }
    if(sValue.compare(".FTF_EQUAL.") == 0)
    {
        nType = Gfc2FragTestFunc::FTF_EQUAL;
        return true;
    }
    if(sValue.compare(".FTF_LEQUAL.") == 0)
    {
        nType = Gfc2FragTestFunc::FTF_LEQUAL;
        return true;
    }
    if(sValue.compare(".FTF_GREATER.") == 0)
    {
        nType = Gfc2FragTestFunc::FTF_GREATER;
        return true;
    }
    if(sValue.compare(".FTF_NOTEQUAL.") == 0)
    {
        nType = Gfc2FragTestFunc::FTF_NOTEQUAL;
        return true;
    }
    if(sValue.compare(".FTF_GEQUAL.") == 0)
    {
        nType = Gfc2FragTestFunc::FTF_GEQUAL;
        return true;
    }
    if(sValue.compare(".FTF_ALWAYS.") == 0)
    {
        nType = Gfc2FragTestFunc::FTF_ALWAYS;
        return true;
    }
    return false;
}

inline std::string Gfc2GeometryDataTypeToString(Gfc2GeometryDataType nValue)
{
    switch(nValue)
    {
    case Gfc2GeometryDataType::GDT_UNCOMPRESS:
        return ".GDT_UNCOMPRESS.";
        break;
    case Gfc2GeometryDataType::GDT_COMPRESS:
        return ".GDT_COMPRESS.";
        break;
    case Gfc2GeometryDataType::GDT_UNKNOWN:
        return ".GDT_UNKNOWN.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfc2GeometryDataType(const std::string& sValue, Gfc2GeometryDataType& nType)
{
    if(sValue.compare(".GDT_UNCOMPRESS.") == 0)
    {
        nType = Gfc2GeometryDataType::GDT_UNCOMPRESS;
        return true;
    }
    if(sValue.compare(".GDT_COMPRESS.") == 0)
    {
        nType = Gfc2GeometryDataType::GDT_COMPRESS;
        return true;
    }
    if(sValue.compare(".GDT_UNKNOWN.") == 0)
    {
        nType = Gfc2GeometryDataType::GDT_UNKNOWN;
        return true;
    }
    return false;
}

inline std::string Gfc2PrimitiveTypeToString(Gfc2PrimitiveType nValue)
{
    switch(nValue)
    {
    case Gfc2PrimitiveType::PT_POINTS:
        return ".PT_POINTS.";
        break;
    case Gfc2PrimitiveType::PT_LINES:
        return ".PT_LINES.";
        break;
    case Gfc2PrimitiveType::PT_LINE_STRIP:
        return ".PT_LINE_STRIP.";
        break;
    case Gfc2PrimitiveType::PT_TRIANGLES:
        return ".PT_TRIANGLES.";
        break;
    case Gfc2PrimitiveType::PT_TRIANGLE_STRIP:
        return ".PT_TRIANGLE_STRIP.";
        break;
    case Gfc2PrimitiveType::PT_TRIANGLE_FAN:
        return ".PT_TRIANGLE_FAN.";
        break;
    case Gfc2PrimitiveType::PT_UNKNOWN:
        return ".PT_UNKNOWN.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfc2PrimitiveType(const std::string& sValue, Gfc2PrimitiveType& nType)
{
    if(sValue.compare(".PT_POINTS.") == 0)
    {
        nType = Gfc2PrimitiveType::PT_POINTS;
        return true;
    }
    if(sValue.compare(".PT_LINES.") == 0)
    {
        nType = Gfc2PrimitiveType::PT_LINES;
        return true;
    }
    if(sValue.compare(".PT_LINE_STRIP.") == 0)
    {
        nType = Gfc2PrimitiveType::PT_LINE_STRIP;
        return true;
    }
    if(sValue.compare(".PT_TRIANGLES.") == 0)
    {
        nType = Gfc2PrimitiveType::PT_TRIANGLES;
        return true;
    }
    if(sValue.compare(".PT_TRIANGLE_STRIP.") == 0)
    {
        nType = Gfc2PrimitiveType::PT_TRIANGLE_STRIP;
        return true;
    }
    if(sValue.compare(".PT_TRIANGLE_FAN.") == 0)
    {
        nType = Gfc2PrimitiveType::PT_TRIANGLE_FAN;
        return true;
    }
    if(sValue.compare(".PT_UNKNOWN.") == 0)
    {
        nType = Gfc2PrimitiveType::PT_UNKNOWN;
        return true;
    }
    return false;
}

inline std::string Gfc2SceneBlendFactorToString(Gfc2SceneBlendFactor nValue)
{
    switch(nValue)
    {
    case Gfc2SceneBlendFactor::SBF_DST_ALPHA:
        return ".SBF_DST_ALPHA.";
        break;
    case Gfc2SceneBlendFactor::SBF_DST_COLOR:
        return ".SBF_DST_COLOR.";
        break;
    case Gfc2SceneBlendFactor::SBF_ONE:
        return ".SBF_ONE.";
        break;
    case Gfc2SceneBlendFactor::SBF_ONE_MINUS_DST_COLOR:
        return ".SBF_ONE_MINUS_DST_COLOR.";
        break;
    case Gfc2SceneBlendFactor::SBF_ONE_MINUS_DST_ALPHA:
        return ".SBF_ONE_MINUS_DST_ALPHA.";
        break;
    case Gfc2SceneBlendFactor::SBF_ONE_MINUS_SRC_ALPHA:
        return ".SBF_ONE_MINUS_SRC_ALPHA.";
        break;
    case Gfc2SceneBlendFactor::SBF_ONE_MINUS_SRC_COLOR:
        return ".SBF_ONE_MINUS_SRC_COLOR.";
        break;
    case Gfc2SceneBlendFactor::SBF_SRC_ALPHA:
        return ".SBF_SRC_ALPHA.";
        break;
    case Gfc2SceneBlendFactor::SBF_SRC_ALPHA_SATURATE:
        return ".SBF_SRC_ALPHA_SATURATE.";
        break;
    case Gfc2SceneBlendFactor::SBF_SRC_COLOR:
        return ".SBF_SRC_COLOR.";
        break;
    case Gfc2SceneBlendFactor::SBF_ZERO:
        return ".SBF_ZERO.";
        break;
    case Gfc2SceneBlendFactor::SBF_CONSTANT_COLOR:
        return ".SBF_CONSTANT_COLOR.";
        break;
    case Gfc2SceneBlendFactor::SBF_ONE_MINUS_CONSTANT_COLOR:
        return ".SBF_ONE_MINUS_CONSTANT_COLOR.";
        break;
    case Gfc2SceneBlendFactor::SBF_CONSTANT_ALPHA:
        return ".SBF_CONSTANT_ALPHA.";
        break;
    case Gfc2SceneBlendFactor::SBF_ONE_MINUS_CONSTANT_ALPHA:
        return ".SBF_ONE_MINUS_CONSTANT_ALPHA.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfc2SceneBlendFactor(const std::string& sValue, Gfc2SceneBlendFactor& nType)
{
    if(sValue.compare(".SBF_DST_ALPHA.") == 0)
    {
        nType = Gfc2SceneBlendFactor::SBF_DST_ALPHA;
        return true;
    }
    if(sValue.compare(".SBF_DST_COLOR.") == 0)
    {
        nType = Gfc2SceneBlendFactor::SBF_DST_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_ONE.") == 0)
    {
        nType = Gfc2SceneBlendFactor::SBF_ONE;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_DST_COLOR.") == 0)
    {
        nType = Gfc2SceneBlendFactor::SBF_ONE_MINUS_DST_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_DST_ALPHA.") == 0)
    {
        nType = Gfc2SceneBlendFactor::SBF_ONE_MINUS_DST_ALPHA;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_SRC_ALPHA.") == 0)
    {
        nType = Gfc2SceneBlendFactor::SBF_ONE_MINUS_SRC_ALPHA;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_SRC_COLOR.") == 0)
    {
        nType = Gfc2SceneBlendFactor::SBF_ONE_MINUS_SRC_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_SRC_ALPHA.") == 0)
    {
        nType = Gfc2SceneBlendFactor::SBF_SRC_ALPHA;
        return true;
    }
    if(sValue.compare(".SBF_SRC_ALPHA_SATURATE.") == 0)
    {
        nType = Gfc2SceneBlendFactor::SBF_SRC_ALPHA_SATURATE;
        return true;
    }
    if(sValue.compare(".SBF_SRC_COLOR.") == 0)
    {
        nType = Gfc2SceneBlendFactor::SBF_SRC_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_ZERO.") == 0)
    {
        nType = Gfc2SceneBlendFactor::SBF_ZERO;
        return true;
    }
    if(sValue.compare(".SBF_CONSTANT_COLOR.") == 0)
    {
        nType = Gfc2SceneBlendFactor::SBF_CONSTANT_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_CONSTANT_COLOR.") == 0)
    {
        nType = Gfc2SceneBlendFactor::SBF_ONE_MINUS_CONSTANT_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_CONSTANT_ALPHA.") == 0)
    {
        nType = Gfc2SceneBlendFactor::SBF_CONSTANT_ALPHA;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_CONSTANT_ALPHA.") == 0)
    {
        nType = Gfc2SceneBlendFactor::SBF_ONE_MINUS_CONSTANT_ALPHA;
        return true;
    }
    return false;
}

inline std::string Gfc2SweepTypeToString(Gfc2SweepType nValue)
{
    switch(nValue)
    {
    case Gfc2SweepType::ST_Perpendicular:
        return ".ST_Perpendicular.";
        break;
    case Gfc2SweepType::ST_Upright:
        return ".ST_Upright.";
        break;
    case Gfc2SweepType::ST_Facepoint:
        return ".ST_Facepoint.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfc2SweepType(const std::string& sValue, Gfc2SweepType& nType)
{
    if(sValue.compare(".ST_Perpendicular.") == 0)
    {
        nType = Gfc2SweepType::ST_Perpendicular;
        return true;
    }
    if(sValue.compare(".ST_Upright.") == 0)
    {
        nType = Gfc2SweepType::ST_Upright;
        return true;
    }
    if(sValue.compare(".ST_Facepoint.") == 0)
    {
        nType = Gfc2SweepType::ST_Facepoint;
        return true;
    }
    return false;
}

#endif
