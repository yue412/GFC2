#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <string>
#include "Gfc2String.h"

typedef bool Gfc2Boolean;

typedef double Gfc2Date;

typedef double Gfc2Double;

typedef Gfc2String Gfc2Elev;

typedef std::string Gfc2Identity;

typedef int Gfc2Integer;

typedef Gfc2String Gfc2Label;

typedef Gfc2String Gfc2Text;

enum Gfc2ArcType
{
    AT_LINE,
    AT_ACS,
    AT_CS,
    AT_ACL,
    AT_CL
};

enum Gfc2AxisNoPosEnum
{
    NONE_POS,
    START_POS,
    END_POS,
    BOTH_POS
};

enum Gfc2AxisType
{
    SKJ,
    XKJ,
    ZJS,
    YJS
};

enum Gfc2FaceMode
{
    FM_FRONT,
    FM_BACK,
    FM_FRONT_AND_BACK
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

enum Gfc2SizeMarkType
{
    LENGTHMARK,
    ALIGNMARK,
    ANGLEMARK,
    ARCMARK
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
    case AT_LINE:
        return ".AT_LINE.";
        break;
    case AT_ACS:
        return ".AT_ACS.";
        break;
    case AT_CS:
        return ".AT_CS.";
        break;
    case AT_ACL:
        return ".AT_ACL.";
        break;
    case AT_CL:
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
        nType = AT_LINE;
        return true;
    }
    if(sValue.compare(".AT_ACS.") == 0)
    {
        nType = AT_ACS;
        return true;
    }
    if(sValue.compare(".AT_CS.") == 0)
    {
        nType = AT_CS;
        return true;
    }
    if(sValue.compare(".AT_ACL.") == 0)
    {
        nType = AT_ACL;
        return true;
    }
    if(sValue.compare(".AT_CL.") == 0)
    {
        nType = AT_CL;
        return true;
    }
    return false;
}

inline std::string Gfc2AxisNoPosEnumToString(Gfc2AxisNoPosEnum nValue)
{
    switch(nValue)
    {
    case NONE_POS:
        return ".NONE_POS.";
        break;
    case START_POS:
        return ".START_POS.";
        break;
    case END_POS:
        return ".END_POS.";
        break;
    case BOTH_POS:
        return ".BOTH_POS.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfc2AxisNoPosEnum(const std::string& sValue, Gfc2AxisNoPosEnum& nType)
{
    if(sValue.compare(".NONE_POS.") == 0)
    {
        nType = NONE_POS;
        return true;
    }
    if(sValue.compare(".START_POS.") == 0)
    {
        nType = START_POS;
        return true;
    }
    if(sValue.compare(".END_POS.") == 0)
    {
        nType = END_POS;
        return true;
    }
    if(sValue.compare(".BOTH_POS.") == 0)
    {
        nType = BOTH_POS;
        return true;
    }
    return false;
}

inline std::string Gfc2AxisTypeToString(Gfc2AxisType nValue)
{
    switch(nValue)
    {
    case SKJ:
        return ".SKJ.";
        break;
    case XKJ:
        return ".XKJ.";
        break;
    case ZJS:
        return ".ZJS.";
        break;
    case YJS:
        return ".YJS.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfc2AxisType(const std::string& sValue, Gfc2AxisType& nType)
{
    if(sValue.compare(".SKJ.") == 0)
    {
        nType = SKJ;
        return true;
    }
    if(sValue.compare(".XKJ.") == 0)
    {
        nType = XKJ;
        return true;
    }
    if(sValue.compare(".ZJS.") == 0)
    {
        nType = ZJS;
        return true;
    }
    if(sValue.compare(".YJS.") == 0)
    {
        nType = YJS;
        return true;
    }
    return false;
}

inline std::string Gfc2FaceModeToString(Gfc2FaceMode nValue)
{
    switch(nValue)
    {
    case FM_FRONT:
        return ".FM_FRONT.";
        break;
    case FM_BACK:
        return ".FM_BACK.";
        break;
    case FM_FRONT_AND_BACK:
        return ".FM_FRONT_AND_BACK.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfc2FaceMode(const std::string& sValue, Gfc2FaceMode& nType)
{
    if(sValue.compare(".FM_FRONT.") == 0)
    {
        nType = FM_FRONT;
        return true;
    }
    if(sValue.compare(".FM_BACK.") == 0)
    {
        nType = FM_BACK;
        return true;
    }
    if(sValue.compare(".FM_FRONT_AND_BACK.") == 0)
    {
        nType = FM_FRONT_AND_BACK;
        return true;
    }
    return false;
}

inline std::string Gfc2FragTestFuncToString(Gfc2FragTestFunc nValue)
{
    switch(nValue)
    {
    case FTF_NEVER:
        return ".FTF_NEVER.";
        break;
    case FTF_LESS:
        return ".FTF_LESS.";
        break;
    case FTF_EQUAL:
        return ".FTF_EQUAL.";
        break;
    case FTF_LEQUAL:
        return ".FTF_LEQUAL.";
        break;
    case FTF_GREATER:
        return ".FTF_GREATER.";
        break;
    case FTF_NOTEQUAL:
        return ".FTF_NOTEQUAL.";
        break;
    case FTF_GEQUAL:
        return ".FTF_GEQUAL.";
        break;
    case FTF_ALWAYS:
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
        nType = FTF_NEVER;
        return true;
    }
    if(sValue.compare(".FTF_LESS.") == 0)
    {
        nType = FTF_LESS;
        return true;
    }
    if(sValue.compare(".FTF_EQUAL.") == 0)
    {
        nType = FTF_EQUAL;
        return true;
    }
    if(sValue.compare(".FTF_LEQUAL.") == 0)
    {
        nType = FTF_LEQUAL;
        return true;
    }
    if(sValue.compare(".FTF_GREATER.") == 0)
    {
        nType = FTF_GREATER;
        return true;
    }
    if(sValue.compare(".FTF_NOTEQUAL.") == 0)
    {
        nType = FTF_NOTEQUAL;
        return true;
    }
    if(sValue.compare(".FTF_GEQUAL.") == 0)
    {
        nType = FTF_GEQUAL;
        return true;
    }
    if(sValue.compare(".FTF_ALWAYS.") == 0)
    {
        nType = FTF_ALWAYS;
        return true;
    }
    return false;
}

inline std::string Gfc2GeometryDataTypeToString(Gfc2GeometryDataType nValue)
{
    switch(nValue)
    {
    case GDT_UNCOMPRESS:
        return ".GDT_UNCOMPRESS.";
        break;
    case GDT_COMPRESS:
        return ".GDT_COMPRESS.";
        break;
    case GDT_UNKNOWN:
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
        nType = GDT_UNCOMPRESS;
        return true;
    }
    if(sValue.compare(".GDT_COMPRESS.") == 0)
    {
        nType = GDT_COMPRESS;
        return true;
    }
    if(sValue.compare(".GDT_UNKNOWN.") == 0)
    {
        nType = GDT_UNKNOWN;
        return true;
    }
    return false;
}

inline std::string Gfc2PrimitiveTypeToString(Gfc2PrimitiveType nValue)
{
    switch(nValue)
    {
    case PT_POINTS:
        return ".PT_POINTS.";
        break;
    case PT_LINES:
        return ".PT_LINES.";
        break;
    case PT_LINE_STRIP:
        return ".PT_LINE_STRIP.";
        break;
    case PT_TRIANGLES:
        return ".PT_TRIANGLES.";
        break;
    case PT_TRIANGLE_STRIP:
        return ".PT_TRIANGLE_STRIP.";
        break;
    case PT_TRIANGLE_FAN:
        return ".PT_TRIANGLE_FAN.";
        break;
    case PT_UNKNOWN:
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
        nType = PT_POINTS;
        return true;
    }
    if(sValue.compare(".PT_LINES.") == 0)
    {
        nType = PT_LINES;
        return true;
    }
    if(sValue.compare(".PT_LINE_STRIP.") == 0)
    {
        nType = PT_LINE_STRIP;
        return true;
    }
    if(sValue.compare(".PT_TRIANGLES.") == 0)
    {
        nType = PT_TRIANGLES;
        return true;
    }
    if(sValue.compare(".PT_TRIANGLE_STRIP.") == 0)
    {
        nType = PT_TRIANGLE_STRIP;
        return true;
    }
    if(sValue.compare(".PT_TRIANGLE_FAN.") == 0)
    {
        nType = PT_TRIANGLE_FAN;
        return true;
    }
    if(sValue.compare(".PT_UNKNOWN.") == 0)
    {
        nType = PT_UNKNOWN;
        return true;
    }
    return false;
}

inline std::string Gfc2SceneBlendFactorToString(Gfc2SceneBlendFactor nValue)
{
    switch(nValue)
    {
    case SBF_DST_ALPHA:
        return ".SBF_DST_ALPHA.";
        break;
    case SBF_DST_COLOR:
        return ".SBF_DST_COLOR.";
        break;
    case SBF_ONE:
        return ".SBF_ONE.";
        break;
    case SBF_ONE_MINUS_DST_COLOR:
        return ".SBF_ONE_MINUS_DST_COLOR.";
        break;
    case SBF_ONE_MINUS_DST_ALPHA:
        return ".SBF_ONE_MINUS_DST_ALPHA.";
        break;
    case SBF_ONE_MINUS_SRC_ALPHA:
        return ".SBF_ONE_MINUS_SRC_ALPHA.";
        break;
    case SBF_ONE_MINUS_SRC_COLOR:
        return ".SBF_ONE_MINUS_SRC_COLOR.";
        break;
    case SBF_SRC_ALPHA:
        return ".SBF_SRC_ALPHA.";
        break;
    case SBF_SRC_ALPHA_SATURATE:
        return ".SBF_SRC_ALPHA_SATURATE.";
        break;
    case SBF_SRC_COLOR:
        return ".SBF_SRC_COLOR.";
        break;
    case SBF_ZERO:
        return ".SBF_ZERO.";
        break;
    case SBF_CONSTANT_COLOR:
        return ".SBF_CONSTANT_COLOR.";
        break;
    case SBF_ONE_MINUS_CONSTANT_COLOR:
        return ".SBF_ONE_MINUS_CONSTANT_COLOR.";
        break;
    case SBF_CONSTANT_ALPHA:
        return ".SBF_CONSTANT_ALPHA.";
        break;
    case SBF_ONE_MINUS_CONSTANT_ALPHA:
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
        nType = SBF_DST_ALPHA;
        return true;
    }
    if(sValue.compare(".SBF_DST_COLOR.") == 0)
    {
        nType = SBF_DST_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_ONE.") == 0)
    {
        nType = SBF_ONE;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_DST_COLOR.") == 0)
    {
        nType = SBF_ONE_MINUS_DST_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_DST_ALPHA.") == 0)
    {
        nType = SBF_ONE_MINUS_DST_ALPHA;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_SRC_ALPHA.") == 0)
    {
        nType = SBF_ONE_MINUS_SRC_ALPHA;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_SRC_COLOR.") == 0)
    {
        nType = SBF_ONE_MINUS_SRC_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_SRC_ALPHA.") == 0)
    {
        nType = SBF_SRC_ALPHA;
        return true;
    }
    if(sValue.compare(".SBF_SRC_ALPHA_SATURATE.") == 0)
    {
        nType = SBF_SRC_ALPHA_SATURATE;
        return true;
    }
    if(sValue.compare(".SBF_SRC_COLOR.") == 0)
    {
        nType = SBF_SRC_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_ZERO.") == 0)
    {
        nType = SBF_ZERO;
        return true;
    }
    if(sValue.compare(".SBF_CONSTANT_COLOR.") == 0)
    {
        nType = SBF_CONSTANT_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_CONSTANT_COLOR.") == 0)
    {
        nType = SBF_ONE_MINUS_CONSTANT_COLOR;
        return true;
    }
    if(sValue.compare(".SBF_CONSTANT_ALPHA.") == 0)
    {
        nType = SBF_CONSTANT_ALPHA;
        return true;
    }
    if(sValue.compare(".SBF_ONE_MINUS_CONSTANT_ALPHA.") == 0)
    {
        nType = SBF_ONE_MINUS_CONSTANT_ALPHA;
        return true;
    }
    return false;
}

inline std::string Gfc2SizeMarkTypeToString(Gfc2SizeMarkType nValue)
{
    switch(nValue)
    {
    case LENGTHMARK:
        return ".LENGTHMARK.";
        break;
    case ALIGNMARK:
        return ".ALIGNMARK.";
        break;
    case ANGLEMARK:
        return ".ANGLEMARK.";
        break;
    case ARCMARK:
        return ".ARCMARK.";
        break;
    default:
        assert(false);
        return "";
    }
}

inline bool StringToGfc2SizeMarkType(const std::string& sValue, Gfc2SizeMarkType& nType)
{
    if(sValue.compare(".LENGTHMARK.") == 0)
    {
        nType = LENGTHMARK;
        return true;
    }
    if(sValue.compare(".ALIGNMARK.") == 0)
    {
        nType = ALIGNMARK;
        return true;
    }
    if(sValue.compare(".ANGLEMARK.") == 0)
    {
        nType = ANGLEMARK;
        return true;
    }
    if(sValue.compare(".ARCMARK.") == 0)
    {
        nType = ARCMARK;
        return true;
    }
    return false;
}

inline std::string Gfc2SweepTypeToString(Gfc2SweepType nValue)
{
    switch(nValue)
    {
    case ST_Perpendicular:
        return ".ST_Perpendicular.";
        break;
    case ST_Upright:
        return ".ST_Upright.";
        break;
    case ST_Facepoint:
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
        nType = ST_Perpendicular;
        return true;
    }
    if(sValue.compare(".ST_Upright.") == 0)
    {
        nType = ST_Upright;
        return true;
    }
    if(sValue.compare(".ST_Facepoint.") == 0)
    {
        nType = ST_Facepoint;
        return true;
    }
    return false;
}

#endif
