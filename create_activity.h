#pragma once
#include <string>

class CreateSystemActivityRequest
{
    friend class CreateSystemActivityRespons;
public:
    CreateSystemActivityRequest() {}
    CreateSystemActivityRequest(const std::string &json)
    {
        this->Deserialize(json);
    }
    template <typename Writer>
    void Serialize(Writer &writer) const
    {
        writer.StartObject();
        SERIALIZE_MEMBER(writer, lType);
        SERIALIZE_MEMBER(writer, sTitle);
        SERIALIZE_MEMBER(writer, sIconLink);
        SERIALIZE_MEMBER(writer, sDescript);
        SERIALIZE_MEMBER(writer, sContent);
        SERIALIZE_MEMBER(writer, sMoreLink);
        SERIALIZE_MEMBER(writer, lFinishTime);
        writer.EndObject();
    }

    void toString(std::string &json)
    {
        StringBuffer sb;
        Writer<StringBuffer> writer(sb);
        Serialize(writer);
        json = sb.GetString();
    }

    void Deserialize(const string &json)
    {
        try
        {
            Document d;
            if (d.Parse(json.c_str()).HasParseError())
            {
                throw logic_error("parse json error. raw data : " + json);
            }
            SET_DOC_MEMBER(d, lType);
            SET_DOC_MEMBER(d, sTitle);
            SET_DOC_MEMBER(d, sIconLink);
            SET_DOC_MEMBER(d, sDescript);
            SET_DOC_MEMBER(d, sContent);
            SET_DOC_MEMBER(d, sMoreLink);
            SET_DOC_MEMBER(d, lFinishTime);
        }
        catch (const std::exception &e)
        {
            std::string errInfo = ::toString(__FILE__, ":", __LINE__, ":CreateSystemActivityRequest decode error!");
            throw logic_error(errInfo);
        }
    }

    static tars::Int32 handler(const vector<tars::Char> &reqBuf, const map<std::string, std::string> &extraInfo, vector<tars::Char> &rspBuf)
    {
        return 0;
    }

private:
    CInteger _lType;         // 类型
    CString  _sTitle;        // 标题
    CString  _sIconLink;     // 预览图链接
    CString  _sDescript;     // 简介
    CString  _sContent;      // 内容
    CString  _sMoreLink;     // 详情内容链接
    CInteger _lFinishTime;   // 结束时间
};
class CreateSystemActivityRespons
{
public:
    CreateSystemActivityRespons() {}
    CreateSystemActivityRespons(const string &json)
    {
        this->Deserialize(json);
    }
    template <typename Writer>
    void Serialize(Writer &writer) const
    {
        writer.StartObject();
        writer.EndObject();
    }

    void toString(std::string &json)
    {
        StringBuffer sb;
        Writer<StringBuffer> writer(sb);
        Serialize(writer);
        json = sb.GetString();
    }

    void Deserialize(const string &json)
    {
        Document d;
        if (d.Parse(json.c_str()).HasParseError())
        {
            throw logic_error("parse json error. raw data : " + json);
        }
    }

    static tars::Int32 handler(const vector<tars::Char> &reqBuf, const map<std::string, std::string> &extraInfo, vector<tars::Char> &rspBuf)
    {
        FUNC_ENTRY("");
        __TRY__

        // STEP1 解码
        CreateSystemActivityRequest request;
        decode(reqBuf, request);


        // STEP2 具体业务处理
        int64_t resultCode = RESULT_CODE_SUCCESS;
        global::CreateSystemActivityReq req;
        global::CreateSystemActivityResp resp;
        req.iType = request._lType;
        req.sTitle = request._sTitle;
        req.sIconLink = request._sIconLink;
        req.sDescript = request._sDescript;
        req.sContent = request._sContent;
        req.sMoreLink = request._sMoreLink;
        req.lFinishTime = request._lFinishTime;
        int iRet = g_app.getOuterFactoryPtr()->getGlobalServantPrx(request._lType)->createSystemActivity(req, resp);
        if (iRet != 0)
        {
            ROLLLOG_ERROR << "createSystemActivity failed, iRet:" << iRet << ", request._lType:" << request._lType << endl;
            resultCode = RESULT_CODE_FAIL;
        }

        if (iRet == 0)
        {
            g_app.getOuterFactoryPtr()->getPushServerPrx(0)->async_pushMessageRed(NULL, 17);
        }

        // STEP3 填充数据
        encode(resultCode, request, rspBuf);

        __CATCH__
        FUNC_EXIT("", 0);
        return 0;
    }

private:

    static void encode(int64_t resultCode, CreateSystemActivityRequest &request, vector<tars::Char> &rspBuf)
    {
        CreateSystemActivityRespons  response;

        // resultData是数组
        std::string json;
        response.toString(json);
        std::string resultData = "[" + json + "]";

        int64_t totalItems = 1;  //总条数
        int64_t totalPages = 1;  //总页数
        GMResponse rsp(resultCode, "", resultData, totalItems, totalPages);
        std::string resultJson;
        rsp.toString(resultJson);
        rspBuf.assign(resultJson.begin(), resultJson.end());
    }
};