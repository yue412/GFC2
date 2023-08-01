﻿#include "gtest\gtest.h"
#include "GfcEngine\JsonSerializerUtils.h"
#include "GfcClasses\x3\Document.h"

TEST(TestJsonSerializerUtils, parseEntity_1)
{
    std::string s = "{\"$$typeName\":\"Gfc2PropertySet\",\"Name\":\"墙实例\",\"HasProperties\":[{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"分类编码\",\"Extension\":\"{\\\"code\\\":\\\"43111117\\\",\\\"drive\\\":false,\\\"guid\\\":\\\"{b21937a8-04c2-c503-098a-c713139eee1c}\\\",\\\"process\\\":4,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":false,\\\"vis\\\":true}\\n\",\"Val\":\"31211300\"},{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"空间ID\",\"Extension\":\"{\\\"code\\\":\\\"43311511\\\",\\\"drive\\\":false,\\\"guid\\\":\\\"{36eb4755-1894-5dcb-6334-b3319302157a}\\\",\\\"process\\\":4,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":false,\\\"vis\\\":true}\\n\",\"Val\":\"b3bb93df-3c7e-4c30-8cb3-a05f1e76f863\"},{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"族名称\",\"Extension\":\"{\\\"code\\\":\\\"43111131\\\",\\\"drive\\\":false,\\\"guid\\\":\\\"{dbe9a73c-261b-9937-10a6-fcf022c26ab5}\\\",\\\"process\\\":4,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":false,\\\"vis\\\":true}\\n\",\"Val\":\"墙\"},{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"类型名称\",\"Extension\":\"{\\\"code\\\":\\\"43111133\\\",\\\"drive\\\":false,\\\"guid\\\":\\\"{4f0f3027-cfe1-14b2-f209-ddc11877a944}\\\",\\\"process\\\":4,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":false,\\\"vis\\\":true}\\n\",\"Val\":\"200\"},{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"元素编号\",\"Extension\":\"{\\\"code\\\":\\\"43111311\\\",\\\"drive\\\":false,\\\"guid\\\":\\\"{d8b05042-0438-d460-19a5-0e69cd4fe785}\\\",\\\"process\\\":4,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":false,\\\"vis\\\":true}\\n\",\"Val\":\"2305871321638114167\"},{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"基线\",\"Extension\":\"{\\\"code\\\":\\\"43231321\\\",\\\"drive\\\":false,\\\"guid\\\":\\\"{03855970-8841-de2b-25ac-2e8bc6682f78}\\\",\\\"process\\\":1,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":false,\\\"vis\\\":false}\\n\",\"Val\":\"{TYPE=1,Pos=(-1.00680278428252004232e+04 1.09183681011199951172e+04),Dir=(1.00000000000000000000e+00 0.00000000000000000000e+00),Range=[0.00000000000000000000e+00 9.40000000000000000000e+03]}\"},{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"底部关联标高ID\",\"Extension\":\"{\\\"code\\\":\\\"4323231501\\\",\\\"drive\\\":false,\\\"guid\\\":\\\"{76a3b6ed-83bc-4d5d-eaa6-60a721380820}\\\",\\\"process\\\":4,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":false,\\\"vis\\\":true}\\n\",\"Val\":\"b3bb93df-3c7e-4c30-8cb3-a05f1e76f863\"},{\"$$typeName\":\"Gfc2DoubleProperty\",\"Name\":\"底部标高偏移量\",\"Extension\":\"{\\\"code\\\":\\\"4323231502\\\",\\\"drive\\\":false,\\\"guid\\\":\\\"{3bf84129-ec76-bdb1-a74c-0a56cda61f03}\\\",\\\"process\\\":4,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":5,\\\"typed\\\":false,\\\"vis\\\":true}\\n\",\"Val\":0.0},{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"顶部关联标高ID\",\"Extension\":\"{\\\"code\\\":\\\"4323231901\\\",\\\"drive\\\":false,\\\"guid\\\":\\\"{63d0eeaf-d092-aea2-e109-ca9317b0562a}\\\",\\\"process\\\":4,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":false,\\\"vis\\\":true}\\n\",\"Val\":\"8b73f322-89dc-47f6-8b29-dc7d19b91f97\"},{\"$$typeName\":\"Gfc2DoubleProperty\",\"Name\":\"顶部标高偏移量\",\"Extension\":\"{\\\"code\\\":\\\"4323231902\\\",\\\"drive\\\":false,\\\"guid\\\":\\\"{d81a7912-59df-8dd4-8548-b50e1eee501e}\\\",\\\"process\\\":4,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":5,\\\"typed\\\":false,\\\"vis\\\":true}\\n\",\"Val\":0.0},{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"基线\",\"Extension\":\"{\\\"code\\\":\\\"43231321\\\",\\\"drive\\\":false,\\\"guid\\\":\\\"{03855970-8841-de2b-25ac-2e8bc6682f78}\\\",\\\"process\\\":1,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":false,\\\"vis\\\":false}\\n\",\"Val\":\"{TYPE=1,Pos=(-1.00680278428252004232e+04 1.09183681011199951172e+04),Dir=(1.00000000000000000000e+00 0.00000000000000000000e+00),Range=[0.00000000000000000000e+00 9.40000000000000000000e+03]}\"},{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"面集合\",\"Extension\":\"{\\\"code\\\":\\\"43231335\\\",\\\"drive\\\":false,\\\"guid\\\":\\\"{f5ad1190-66d1-2dab-a8d1-c337880b3b1f}\\\",\\\"process\\\":1,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":false,\\\"vis\\\":false}\\n\",\"Val\":\"4,6\"},{\"$$typeName\":\"Gfc2DoubleProperty\",\"Name\":\"厚度\",\"Extension\":\"{\\\"code\\\":\\\"43231717\\\",\\\"drive\\\":true,\\\"guid\\\":\\\"{74996af4-a7d6-c8d1-3a66-f70dc0faa3aa}\\\",\\\"process\\\":1,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":5,\\\"typed\\\":false,\\\"vis\\\":true}\\n\",\"Val\":200.0},{\"$$typeName\":\"Gfc2DoubleProperty\",\"Name\":\"高度\",\"Extension\":\"{\\\"code\\\":\\\"43231715\\\",\\\"drive\\\":true,\\\"guid\\\":\\\"{59019d54-e818-37d1-b53c-6053061d8cd2}\\\",\\\"process\\\":1,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":5,\\\"typed\\\":false,\\\"vis\\\":true}\\n\",\"Val\":3000.0},{\"$$typeName\":\"Gfc2DoubleProperty\",\"Name\":\"长度\",\"Extension\":\"{\\\"code\\\":\\\"43231711\\\",\\\"drive\\\":true,\\\"guid\\\":\\\"{fb6e9de7-8979-5d03-6f9b-f04edf2b67bf}\\\",\\\"process\\\":1,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":5,\\\"typed\\\":false,\\\"vis\\\":true}\\n\",\"Val\":9400.0},{\"$$typeName\":\"Gfc2DoubleProperty\",\"Name\":\"底部高度\",\"Extension\":\"{\\\"code\\\":\\\"4323231503\\\",\\\"drive\\\":true,\\\"guid\\\":\\\"{1848489e-8db1-4df6-1382-bcb2d2dd84f5}\\\",\\\"process\\\":1,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":5,\\\"typed\\\":false,\\\"vis\\\":true}\\n\",\"Val\":0.0},{\"$$typeName\":\"Gfc2DoubleProperty\",\"Name\":\"顶部高度\",\"Extension\":\"{\\\"code\\\":\\\"43232320\\\",\\\"drive\\\":true,\\\"guid\\\":\\\"{72855373-a5c7-2584-6afe-2feece2c0f3e}\\\",\\\"process\\\":1,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":5,\\\"typed\\\":false,\\\"vis\\\":true}\\n\",\"Val\":3000.0},{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"结构墙类型\",\"Extension\":\"{\\\"code\\\":\\\"43511315\\\",\\\"drive\\\":true,\\\"guid\\\":\\\"{235cc3c6-a2ef-39c2-d75b-e8d06342f578}\\\",\\\"process\\\":1,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":false,\\\"vis\\\":true}\\n\",\"Val\":\"4351131501\"},{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"结构墙编号\",\"Extension\":\"{\\\"code\\\":\\\"43511316\\\",\\\"drive\\\":true,\\\"guid\\\":\\\"{33eca730-d97f-3902-55eb-dd4b47d7805c}\\\",\\\"process\\\":1,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":false,\\\"vis\\\":true}\\n\",\"Val\":\"\"},{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"类型名称\",\"Extension\":\"{\\\"code\\\":\\\"43111133\\\",\\\"drive\\\":true,\\\"guid\\\":\\\"{4f0f3027-cfe1-14b2-f209-ddc11877a944}\\\",\\\"process\\\":1,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":true,\\\"vis\\\":true}\\n\",\"Val\":\"200\"},{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"族名称\",\"Extension\":\"{\\\"code\\\":\\\"43111131\\\",\\\"drive\\\":true,\\\"guid\\\":\\\"{dbe9a73c-261b-9937-10a6-fcf022c26ab5}\\\",\\\"process\\\":1,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":false,\\\"vis\\\":true}\\n\",\"Val\":\"墙\"},{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"混凝土类型\",\"Extension\":\"{\\\"code\\\":\\\"18100000\\\",\\\"drive\\\":true,\\\"guid\\\":\\\"{cf8a9011-99dc-7280-fabf-1bc7a6487e3a}\\\",\\\"process\\\":1,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":true,\\\"vis\\\":true}\\n\",\"Val\":\"18101000\"},{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"混凝土等级\",\"Extension\":\"{\\\"code\\\":\\\"18500000\\\",\\\"drive\\\":true,\\\"guid\\\":\\\"{e1197a78-f390-033d-304e-10469b51bc14}\\\",\\\"process\\\":1,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":true,\\\"vis\\\":true}\\n\",\"Val\":\"18503000\"},{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"混凝土抗渗等级\",\"Extension\":\"{\\\"code\\\":\\\"18600000\\\",\\\"drive\\\":true,\\\"guid\\\":\\\"{563cbe76-8258-e05d-b097-62b616d45c34}\\\",\\\"process\\\":1,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":true,\\\"vis\\\":true}\\n\",\"Val\":\"18604000\"},{\"$$typeName\":\"Gfc2StringProperty\",\"Name\":\"主体材质\",\"Extension\":\"{\\\"code\\\":\\\"43511527\\\",\\\"drive\\\":true,\\\"guid\\\":\\\"{f334c781-d386-d7b4-4624-9f0385e1b9f7}\\\",\\\"process\\\":1,\\\"schemaVersion\\\":1,\\\"std\\\":true,\\\"storage\\\":6,\\\"typed\\\":true,\\\"vis\\\":true}\\n\",\"Val\":\"4351152701\"}],\"$$schemaVersion\":\"GFC3X0\"}";
    //std::string s = "{\"$$typeName\":\"Gfc2PropertySet\"}";
    rapidjson::Document d;
    gfc::engine::JsonWrapper jObj(&d);
    bool success = jObj.Parse(s);
    EXPECT_EQ(true, success);
    gfc::classes::x3::CDocument oDoc;
    auto pEntity = gfc::engine::CJsonSerializerUtils::parseEntity(nullptr, &oDoc, jObj);

    EXPECT_NE(nullptr, pEntity);
    EXPECT_EQ(true, L"GfcPropertySet" == pEntity->entityName());
}
