/**
 *
 *  Customers.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Customers.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::workersdb;

const std::string Customers::Cols::_id = "id";
const std::string Customers::Cols::_full_name = "full_name";
const std::string Customers::Cols::_email = "email";
const std::string Customers::Cols::_contact = "contact";
const std::string Customers::Cols::_address = "address";
const std::string Customers::Cols::_locality = "locality";
const std::string Customers::Cols::_district = "district";
const std::string Customers::Cols::_state = "state";
const std::string Customers::primaryKeyName = "id";
const bool Customers::hasPrimaryKey = true;
const std::string Customers::tableName = "customers";

const std::vector<typename Customers::MetaData> Customers::metaData_={
{"id","uint32_t","int(10) unsigned",4,0,1,1},
{"full_name","std::string","varchar(60)",60,0,0,1},
{"email","std::string","varchar(120)",120,0,0,1},
{"contact","uint64_t","bigint(20) unsigned",8,0,0,1},
{"address","std::string","text",0,0,0,1},
{"locality","uint32_t","int(10) unsigned",4,0,0,1},
{"district","uint32_t","int(10) unsigned",4,0,0,1},
{"state","uint32_t","int(10) unsigned",4,0,0,1}
};
const std::string &Customers::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Customers::Customers(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<uint32_t>(r["id"].as<uint32_t>());
        }
        if(!r["full_name"].isNull())
        {
            fullName_=std::make_shared<std::string>(r["full_name"].as<std::string>());
        }
        if(!r["email"].isNull())
        {
            email_=std::make_shared<std::string>(r["email"].as<std::string>());
        }
        if(!r["contact"].isNull())
        {
            contact_=std::make_shared<uint64_t>(r["contact"].as<uint64_t>());
        }
        if(!r["address"].isNull())
        {
            address_=std::make_shared<std::string>(r["address"].as<std::string>());
        }
        if(!r["locality"].isNull())
        {
            locality_=std::make_shared<uint32_t>(r["locality"].as<uint32_t>());
        }
        if(!r["district"].isNull())
        {
            district_=std::make_shared<uint32_t>(r["district"].as<uint32_t>());
        }
        if(!r["state"].isNull())
        {
            state_=std::make_shared<uint32_t>(r["state"].as<uint32_t>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 8 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<uint32_t>(r[index].as<uint32_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            fullName_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            email_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            contact_=std::make_shared<uint64_t>(r[index].as<uint64_t>());
        }
        index = offset + 4;
        if(!r[index].isNull())
        {
            address_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 5;
        if(!r[index].isNull())
        {
            locality_=std::make_shared<uint32_t>(r[index].as<uint32_t>());
        }
        index = offset + 6;
        if(!r[index].isNull())
        {
            district_=std::make_shared<uint32_t>(r[index].as<uint32_t>());
        }
        index = offset + 7;
        if(!r[index].isNull())
        {
            state_=std::make_shared<uint32_t>(r[index].as<uint32_t>());
        }
    }

}

Customers::Customers(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 8)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<uint32_t>((uint32_t)pJson[pMasqueradingVector[0]].asUInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            fullName_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            email_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            contact_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[3]].asUInt64());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            address_=std::make_shared<std::string>(pJson[pMasqueradingVector[4]].asString());
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            locality_=std::make_shared<uint32_t>((uint32_t)pJson[pMasqueradingVector[5]].asUInt64());
        }
    }
    if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
    {
        dirtyFlag_[6] = true;
        if(!pJson[pMasqueradingVector[6]].isNull())
        {
            district_=std::make_shared<uint32_t>((uint32_t)pJson[pMasqueradingVector[6]].asUInt64());
        }
    }
    if(!pMasqueradingVector[7].empty() && pJson.isMember(pMasqueradingVector[7]))
    {
        dirtyFlag_[7] = true;
        if(!pJson[pMasqueradingVector[7]].isNull())
        {
            state_=std::make_shared<uint32_t>((uint32_t)pJson[pMasqueradingVector[7]].asUInt64());
        }
    }
}

Customers::Customers(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<uint32_t>((uint32_t)pJson["id"].asUInt64());
        }
    }
    if(pJson.isMember("full_name"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["full_name"].isNull())
        {
            fullName_=std::make_shared<std::string>(pJson["full_name"].asString());
        }
    }
    if(pJson.isMember("email"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["email"].isNull())
        {
            email_=std::make_shared<std::string>(pJson["email"].asString());
        }
    }
    if(pJson.isMember("contact"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["contact"].isNull())
        {
            contact_=std::make_shared<uint64_t>((uint64_t)pJson["contact"].asUInt64());
        }
    }
    if(pJson.isMember("address"))
    {
        dirtyFlag_[4]=true;
        if(!pJson["address"].isNull())
        {
            address_=std::make_shared<std::string>(pJson["address"].asString());
        }
    }
    if(pJson.isMember("locality"))
    {
        dirtyFlag_[5]=true;
        if(!pJson["locality"].isNull())
        {
            locality_=std::make_shared<uint32_t>((uint32_t)pJson["locality"].asUInt64());
        }
    }
    if(pJson.isMember("district"))
    {
        dirtyFlag_[6]=true;
        if(!pJson["district"].isNull())
        {
            district_=std::make_shared<uint32_t>((uint32_t)pJson["district"].asUInt64());
        }
    }
    if(pJson.isMember("state"))
    {
        dirtyFlag_[7]=true;
        if(!pJson["state"].isNull())
        {
            state_=std::make_shared<uint32_t>((uint32_t)pJson["state"].asUInt64());
        }
    }
}

void Customers::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 8)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<uint32_t>((uint32_t)pJson[pMasqueradingVector[0]].asUInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            fullName_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            email_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            contact_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[3]].asUInt64());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            address_=std::make_shared<std::string>(pJson[pMasqueradingVector[4]].asString());
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            locality_=std::make_shared<uint32_t>((uint32_t)pJson[pMasqueradingVector[5]].asUInt64());
        }
    }
    if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
    {
        dirtyFlag_[6] = true;
        if(!pJson[pMasqueradingVector[6]].isNull())
        {
            district_=std::make_shared<uint32_t>((uint32_t)pJson[pMasqueradingVector[6]].asUInt64());
        }
    }
    if(!pMasqueradingVector[7].empty() && pJson.isMember(pMasqueradingVector[7]))
    {
        dirtyFlag_[7] = true;
        if(!pJson[pMasqueradingVector[7]].isNull())
        {
            state_=std::make_shared<uint32_t>((uint32_t)pJson[pMasqueradingVector[7]].asUInt64());
        }
    }
}

void Customers::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<uint32_t>((uint32_t)pJson["id"].asUInt64());
        }
    }
    if(pJson.isMember("full_name"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["full_name"].isNull())
        {
            fullName_=std::make_shared<std::string>(pJson["full_name"].asString());
        }
    }
    if(pJson.isMember("email"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["email"].isNull())
        {
            email_=std::make_shared<std::string>(pJson["email"].asString());
        }
    }
    if(pJson.isMember("contact"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["contact"].isNull())
        {
            contact_=std::make_shared<uint64_t>((uint64_t)pJson["contact"].asUInt64());
        }
    }
    if(pJson.isMember("address"))
    {
        dirtyFlag_[4] = true;
        if(!pJson["address"].isNull())
        {
            address_=std::make_shared<std::string>(pJson["address"].asString());
        }
    }
    if(pJson.isMember("locality"))
    {
        dirtyFlag_[5] = true;
        if(!pJson["locality"].isNull())
        {
            locality_=std::make_shared<uint32_t>((uint32_t)pJson["locality"].asUInt64());
        }
    }
    if(pJson.isMember("district"))
    {
        dirtyFlag_[6] = true;
        if(!pJson["district"].isNull())
        {
            district_=std::make_shared<uint32_t>((uint32_t)pJson["district"].asUInt64());
        }
    }
    if(pJson.isMember("state"))
    {
        dirtyFlag_[7] = true;
        if(!pJson["state"].isNull())
        {
            state_=std::make_shared<uint32_t>((uint32_t)pJson["state"].asUInt64());
        }
    }
}

const uint32_t &Customers::getValueOfId() const noexcept
{
    const static uint32_t defaultValue = uint32_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<uint32_t> &Customers::getId() const noexcept
{
    return id_;
}
void Customers::setId(const uint32_t &pId) noexcept
{
    id_ = std::make_shared<uint32_t>(pId);
    dirtyFlag_[0] = true;
}
const typename Customers::PrimaryKeyType & Customers::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &Customers::getValueOfFullName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(fullName_)
        return *fullName_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Customers::getFullName() const noexcept
{
    return fullName_;
}
void Customers::setFullName(const std::string &pFullName) noexcept
{
    fullName_ = std::make_shared<std::string>(pFullName);
    dirtyFlag_[1] = true;
}
void Customers::setFullName(std::string &&pFullName) noexcept
{
    fullName_ = std::make_shared<std::string>(std::move(pFullName));
    dirtyFlag_[1] = true;
}

const std::string &Customers::getValueOfEmail() const noexcept
{
    const static std::string defaultValue = std::string();
    if(email_)
        return *email_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Customers::getEmail() const noexcept
{
    return email_;
}
void Customers::setEmail(const std::string &pEmail) noexcept
{
    email_ = std::make_shared<std::string>(pEmail);
    dirtyFlag_[2] = true;
}
void Customers::setEmail(std::string &&pEmail) noexcept
{
    email_ = std::make_shared<std::string>(std::move(pEmail));
    dirtyFlag_[2] = true;
}

const uint64_t &Customers::getValueOfContact() const noexcept
{
    const static uint64_t defaultValue = uint64_t();
    if(contact_)
        return *contact_;
    return defaultValue;
}
const std::shared_ptr<uint64_t> &Customers::getContact() const noexcept
{
    return contact_;
}
void Customers::setContact(const uint64_t &pContact) noexcept
{
    contact_ = std::make_shared<uint64_t>(pContact);
    dirtyFlag_[3] = true;
}

const std::string &Customers::getValueOfAddress() const noexcept
{
    const static std::string defaultValue = std::string();
    if(address_)
        return *address_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Customers::getAddress() const noexcept
{
    return address_;
}
void Customers::setAddress(const std::string &pAddress) noexcept
{
    address_ = std::make_shared<std::string>(pAddress);
    dirtyFlag_[4] = true;
}
void Customers::setAddress(std::string &&pAddress) noexcept
{
    address_ = std::make_shared<std::string>(std::move(pAddress));
    dirtyFlag_[4] = true;
}

const uint32_t &Customers::getValueOfLocality() const noexcept
{
    const static uint32_t defaultValue = uint32_t();
    if(locality_)
        return *locality_;
    return defaultValue;
}
const std::shared_ptr<uint32_t> &Customers::getLocality() const noexcept
{
    return locality_;
}
void Customers::setLocality(const uint32_t &pLocality) noexcept
{
    locality_ = std::make_shared<uint32_t>(pLocality);
    dirtyFlag_[5] = true;
}

const uint32_t &Customers::getValueOfDistrict() const noexcept
{
    const static uint32_t defaultValue = uint32_t();
    if(district_)
        return *district_;
    return defaultValue;
}
const std::shared_ptr<uint32_t> &Customers::getDistrict() const noexcept
{
    return district_;
}
void Customers::setDistrict(const uint32_t &pDistrict) noexcept
{
    district_ = std::make_shared<uint32_t>(pDistrict);
    dirtyFlag_[6] = true;
}

const uint32_t &Customers::getValueOfState() const noexcept
{
    const static uint32_t defaultValue = uint32_t();
    if(state_)
        return *state_;
    return defaultValue;
}
const std::shared_ptr<uint32_t> &Customers::getState() const noexcept
{
    return state_;
}
void Customers::setState(const uint32_t &pState) noexcept
{
    state_ = std::make_shared<uint32_t>(pState);
    dirtyFlag_[7] = true;
}

void Customers::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Customers::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "id",
        "full_name",
        "email",
        "contact",
        "address",
        "locality",
        "district",
        "state"
    };
    return inCols;
}

void Customers::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getId())
        {
            binder << getValueOfId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[1])
    {
        if(getFullName())
        {
            binder << getValueOfFullName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getEmail())
        {
            binder << getValueOfEmail();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getContact())
        {
            binder << getValueOfContact();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getAddress())
        {
            binder << getValueOfAddress();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getLocality())
        {
            binder << getValueOfLocality();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[6])
    {
        if(getDistrict())
        {
            binder << getValueOfDistrict();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[7])
    {
        if(getState())
        {
            binder << getValueOfState();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Customers::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[0])
    {
        ret.push_back(getColumnName(0));
    }
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if(dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    if(dirtyFlag_[3])
    {
        ret.push_back(getColumnName(3));
    }
    if(dirtyFlag_[4])
    {
        ret.push_back(getColumnName(4));
    }
    if(dirtyFlag_[5])
    {
        ret.push_back(getColumnName(5));
    }
    if(dirtyFlag_[6])
    {
        ret.push_back(getColumnName(6));
    }
    if(dirtyFlag_[7])
    {
        ret.push_back(getColumnName(7));
    }
    return ret;
}

void Customers::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getId())
        {
            binder << getValueOfId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[1])
    {
        if(getFullName())
        {
            binder << getValueOfFullName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getEmail())
        {
            binder << getValueOfEmail();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getContact())
        {
            binder << getValueOfContact();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getAddress())
        {
            binder << getValueOfAddress();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getLocality())
        {
            binder << getValueOfLocality();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[6])
    {
        if(getDistrict())
        {
            binder << getValueOfDistrict();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[7])
    {
        if(getState())
        {
            binder << getValueOfState();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Customers::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getFullName())
    {
        ret["full_name"]=getValueOfFullName();
    }
    else
    {
        ret["full_name"]=Json::Value();
    }
    if(getEmail())
    {
        ret["email"]=getValueOfEmail();
    }
    else
    {
        ret["email"]=Json::Value();
    }
    if(getContact())
    {
        ret["contact"]=(Json::UInt64)getValueOfContact();
    }
    else
    {
        ret["contact"]=Json::Value();
    }
    if(getAddress())
    {
        ret["address"]=getValueOfAddress();
    }
    else
    {
        ret["address"]=Json::Value();
    }
    if(getLocality())
    {
        ret["locality"]=getValueOfLocality();
    }
    else
    {
        ret["locality"]=Json::Value();
    }
    if(getDistrict())
    {
        ret["district"]=getValueOfDistrict();
    }
    else
    {
        ret["district"]=Json::Value();
    }
    if(getState())
    {
        ret["state"]=getValueOfState();
    }
    else
    {
        ret["state"]=Json::Value();
    }
    return ret;
}

Json::Value Customers::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 8)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getFullName())
            {
                ret[pMasqueradingVector[1]]=getValueOfFullName();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getEmail())
            {
                ret[pMasqueradingVector[2]]=getValueOfEmail();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getContact())
            {
                ret[pMasqueradingVector[3]]=(Json::UInt64)getValueOfContact();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getAddress())
            {
                ret[pMasqueradingVector[4]]=getValueOfAddress();
            }
            else
            {
                ret[pMasqueradingVector[4]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[5].empty())
        {
            if(getLocality())
            {
                ret[pMasqueradingVector[5]]=getValueOfLocality();
            }
            else
            {
                ret[pMasqueradingVector[5]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[6].empty())
        {
            if(getDistrict())
            {
                ret[pMasqueradingVector[6]]=getValueOfDistrict();
            }
            else
            {
                ret[pMasqueradingVector[6]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[7].empty())
        {
            if(getState())
            {
                ret[pMasqueradingVector[7]]=getValueOfState();
            }
            else
            {
                ret[pMasqueradingVector[7]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getFullName())
    {
        ret["full_name"]=getValueOfFullName();
    }
    else
    {
        ret["full_name"]=Json::Value();
    }
    if(getEmail())
    {
        ret["email"]=getValueOfEmail();
    }
    else
    {
        ret["email"]=Json::Value();
    }
    if(getContact())
    {
        ret["contact"]=(Json::UInt64)getValueOfContact();
    }
    else
    {
        ret["contact"]=Json::Value();
    }
    if(getAddress())
    {
        ret["address"]=getValueOfAddress();
    }
    else
    {
        ret["address"]=Json::Value();
    }
    if(getLocality())
    {
        ret["locality"]=getValueOfLocality();
    }
    else
    {
        ret["locality"]=Json::Value();
    }
    if(getDistrict())
    {
        ret["district"]=getValueOfDistrict();
    }
    else
    {
        ret["district"]=Json::Value();
    }
    if(getState())
    {
        ret["state"]=getValueOfState();
    }
    else
    {
        ret["state"]=Json::Value();
    }
    return ret;
}

bool Customers::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    else
    {
        err="The id column cannot be null";
        return false;
    }
    if(pJson.isMember("full_name"))
    {
        if(!validJsonOfField(1, "full_name", pJson["full_name"], err, true))
            return false;
    }
    else
    {
        err="The full_name column cannot be null";
        return false;
    }
    if(pJson.isMember("email"))
    {
        if(!validJsonOfField(2, "email", pJson["email"], err, true))
            return false;
    }
    else
    {
        err="The email column cannot be null";
        return false;
    }
    if(pJson.isMember("contact"))
    {
        if(!validJsonOfField(3, "contact", pJson["contact"], err, true))
            return false;
    }
    else
    {
        err="The contact column cannot be null";
        return false;
    }
    if(pJson.isMember("address"))
    {
        if(!validJsonOfField(4, "address", pJson["address"], err, true))
            return false;
    }
    else
    {
        err="The address column cannot be null";
        return false;
    }
    if(pJson.isMember("locality"))
    {
        if(!validJsonOfField(5, "locality", pJson["locality"], err, true))
            return false;
    }
    else
    {
        err="The locality column cannot be null";
        return false;
    }
    if(pJson.isMember("district"))
    {
        if(!validJsonOfField(6, "district", pJson["district"], err, true))
            return false;
    }
    else
    {
        err="The district column cannot be null";
        return false;
    }
    if(pJson.isMember("state"))
    {
        if(!validJsonOfField(7, "state", pJson["state"], err, true))
            return false;
    }
    else
    {
        err="The state column cannot be null";
        return false;
    }
    return true;
}
bool Customers::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                   const std::vector<std::string> &pMasqueradingVector,
                                                   std::string &err)
{
    if(pMasqueradingVector.size() != 8)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[0] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[1] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[2].empty())
      {
          if(pJson.isMember(pMasqueradingVector[2]))
          {
              if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[2] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[3].empty())
      {
          if(pJson.isMember(pMasqueradingVector[3]))
          {
              if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[3] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[4].empty())
      {
          if(pJson.isMember(pMasqueradingVector[4]))
          {
              if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[4] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[5].empty())
      {
          if(pJson.isMember(pMasqueradingVector[5]))
          {
              if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[5] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[6].empty())
      {
          if(pJson.isMember(pMasqueradingVector[6]))
          {
              if(!validJsonOfField(6, pMasqueradingVector[6], pJson[pMasqueradingVector[6]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[6] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[7].empty())
      {
          if(pJson.isMember(pMasqueradingVector[7]))
          {
              if(!validJsonOfField(7, pMasqueradingVector[7], pJson[pMasqueradingVector[7]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[7] + " column cannot be null";
            return false;
        }
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Customers::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("full_name"))
    {
        if(!validJsonOfField(1, "full_name", pJson["full_name"], err, false))
            return false;
    }
    if(pJson.isMember("email"))
    {
        if(!validJsonOfField(2, "email", pJson["email"], err, false))
            return false;
    }
    if(pJson.isMember("contact"))
    {
        if(!validJsonOfField(3, "contact", pJson["contact"], err, false))
            return false;
    }
    if(pJson.isMember("address"))
    {
        if(!validJsonOfField(4, "address", pJson["address"], err, false))
            return false;
    }
    if(pJson.isMember("locality"))
    {
        if(!validJsonOfField(5, "locality", pJson["locality"], err, false))
            return false;
    }
    if(pJson.isMember("district"))
    {
        if(!validJsonOfField(6, "district", pJson["district"], err, false))
            return false;
    }
    if(pJson.isMember("state"))
    {
        if(!validJsonOfField(7, "state", pJson["state"], err, false))
            return false;
    }
    return true;
}
bool Customers::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                 const std::vector<std::string> &pMasqueradingVector,
                                                 std::string &err)
{
    if(pMasqueradingVector.size() != 8)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
      if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
      {
          if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
              return false;
      }
      if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
      {
          if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
              return false;
      }
      if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
      {
          if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, false))
              return false;
      }
      if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
      {
          if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, false))
              return false;
      }
      if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
      {
          if(!validJsonOfField(6, pMasqueradingVector[6], pJson[pMasqueradingVector[6]], err, false))
              return false;
      }
      if(!pMasqueradingVector[7].empty() && pJson.isMember(pMasqueradingVector[7]))
      {
          if(!validJsonOfField(7, pMasqueradingVector[7], pJson[pMasqueradingVector[7]], err, false))
              return false;
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Customers::validJsonOfField(size_t index,
                                 const std::string &fieldName,
                                 const Json::Value &pJson,
                                 std::string &err,
                                 bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isUInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 60)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 60)";
                return false;
            }

            break;
        case 2:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 120)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 120)";
                return false;
            }

            break;
        case 3:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isUInt64())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 4:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 5:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isUInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 6:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isUInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 7:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isUInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        default:
            err="Internal error in the server";
            return false;
    }
    return true;
}
