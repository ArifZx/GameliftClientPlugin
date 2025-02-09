﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#pragma once
#include <aws/cognito-identity/CognitoIdentity_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSMap.h>
#include <aws/cognito-identity/model/RoleMapping.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace CognitoIdentity
{
namespace Model
{
  /**
   * <p>Returned in response to a successful <code>GetIdentityPoolRoles</code>
   * operation.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/cognito-identity-2014-06-30/GetIdentityPoolRolesResponse">AWS
   * API Reference</a></p>
   */
  class AWS_COGNITOIDENTITY_API GetIdentityPoolRolesResult
  {
  public:
    GetIdentityPoolRolesResult();
    GetIdentityPoolRolesResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    GetIdentityPoolRolesResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    /**
     * <p>An identity pool ID in the format REGION:GUID.</p>
     */
    inline const Aws::String& GetIdentityPoolId() const{ return m_identityPoolId; }

    /**
     * <p>An identity pool ID in the format REGION:GUID.</p>
     */
    inline void SetIdentityPoolId(const Aws::String& value) { m_identityPoolId = value; }

    /**
     * <p>An identity pool ID in the format REGION:GUID.</p>
     */
    inline void SetIdentityPoolId(Aws::String&& value) { m_identityPoolId = std::move(value); }

    /**
     * <p>An identity pool ID in the format REGION:GUID.</p>
     */
    inline void SetIdentityPoolId(const char* value) { m_identityPoolId.assign(value); }

    /**
     * <p>An identity pool ID in the format REGION:GUID.</p>
     */
    inline GetIdentityPoolRolesResult& WithIdentityPoolId(const Aws::String& value) { SetIdentityPoolId(value); return *this;}

    /**
     * <p>An identity pool ID in the format REGION:GUID.</p>
     */
    inline GetIdentityPoolRolesResult& WithIdentityPoolId(Aws::String&& value) { SetIdentityPoolId(std::move(value)); return *this;}

    /**
     * <p>An identity pool ID in the format REGION:GUID.</p>
     */
    inline GetIdentityPoolRolesResult& WithIdentityPoolId(const char* value) { SetIdentityPoolId(value); return *this;}


    /**
     * <p>The map of roles associated with this pool. Currently only authenticated and
     * unauthenticated roles are supported.</p>
     */
    inline const Aws::Map<Aws::String, Aws::String>& GetRoles() const{ return m_roles; }

    /**
     * <p>The map of roles associated with this pool. Currently only authenticated and
     * unauthenticated roles are supported.</p>
     */
    inline void SetRoles(const Aws::Map<Aws::String, Aws::String>& value) { m_roles = value; }

    /**
     * <p>The map of roles associated with this pool. Currently only authenticated and
     * unauthenticated roles are supported.</p>
     */
    inline void SetRoles(Aws::Map<Aws::String, Aws::String>&& value) { m_roles = std::move(value); }

    /**
     * <p>The map of roles associated with this pool. Currently only authenticated and
     * unauthenticated roles are supported.</p>
     */
    inline GetIdentityPoolRolesResult& WithRoles(const Aws::Map<Aws::String, Aws::String>& value) { SetRoles(value); return *this;}

    /**
     * <p>The map of roles associated with this pool. Currently only authenticated and
     * unauthenticated roles are supported.</p>
     */
    inline GetIdentityPoolRolesResult& WithRoles(Aws::Map<Aws::String, Aws::String>&& value) { SetRoles(std::move(value)); return *this;}

    /**
     * <p>The map of roles associated with this pool. Currently only authenticated and
     * unauthenticated roles are supported.</p>
     */
    inline GetIdentityPoolRolesResult& AddRoles(const Aws::String& key, const Aws::String& value) { m_roles.emplace(key, value); return *this; }

    /**
     * <p>The map of roles associated with this pool. Currently only authenticated and
     * unauthenticated roles are supported.</p>
     */
    inline GetIdentityPoolRolesResult& AddRoles(Aws::String&& key, const Aws::String& value) { m_roles.emplace(std::move(key), value); return *this; }

    /**
     * <p>The map of roles associated with this pool. Currently only authenticated and
     * unauthenticated roles are supported.</p>
     */
    inline GetIdentityPoolRolesResult& AddRoles(const Aws::String& key, Aws::String&& value) { m_roles.emplace(key, std::move(value)); return *this; }

    /**
     * <p>The map of roles associated with this pool. Currently only authenticated and
     * unauthenticated roles are supported.</p>
     */
    inline GetIdentityPoolRolesResult& AddRoles(Aws::String&& key, Aws::String&& value) { m_roles.emplace(std::move(key), std::move(value)); return *this; }

    /**
     * <p>The map of roles associated with this pool. Currently only authenticated and
     * unauthenticated roles are supported.</p>
     */
    inline GetIdentityPoolRolesResult& AddRoles(const char* key, Aws::String&& value) { m_roles.emplace(key, std::move(value)); return *this; }

    /**
     * <p>The map of roles associated with this pool. Currently only authenticated and
     * unauthenticated roles are supported.</p>
     */
    inline GetIdentityPoolRolesResult& AddRoles(Aws::String&& key, const char* value) { m_roles.emplace(std::move(key), value); return *this; }

    /**
     * <p>The map of roles associated with this pool. Currently only authenticated and
     * unauthenticated roles are supported.</p>
     */
    inline GetIdentityPoolRolesResult& AddRoles(const char* key, const char* value) { m_roles.emplace(key, value); return *this; }


    /**
     * <p>How users for a specific identity provider are to mapped to roles. This is a
     * String-to-<a>RoleMapping</a> object map. The string identifies the identity
     * provider, for example, "graph.facebook.com" or
     * "cognito-idp.us-east-1.amazonaws.com/us-east-1_abcdefghi:app_client_id".</p>
     */
    inline const Aws::Map<Aws::String, RoleMapping>& GetRoleMappings() const{ return m_roleMappings; }

    /**
     * <p>How users for a specific identity provider are to mapped to roles. This is a
     * String-to-<a>RoleMapping</a> object map. The string identifies the identity
     * provider, for example, "graph.facebook.com" or
     * "cognito-idp.us-east-1.amazonaws.com/us-east-1_abcdefghi:app_client_id".</p>
     */
    inline void SetRoleMappings(const Aws::Map<Aws::String, RoleMapping>& value) { m_roleMappings = value; }

    /**
     * <p>How users for a specific identity provider are to mapped to roles. This is a
     * String-to-<a>RoleMapping</a> object map. The string identifies the identity
     * provider, for example, "graph.facebook.com" or
     * "cognito-idp.us-east-1.amazonaws.com/us-east-1_abcdefghi:app_client_id".</p>
     */
    inline void SetRoleMappings(Aws::Map<Aws::String, RoleMapping>&& value) { m_roleMappings = std::move(value); }

    /**
     * <p>How users for a specific identity provider are to mapped to roles. This is a
     * String-to-<a>RoleMapping</a> object map. The string identifies the identity
     * provider, for example, "graph.facebook.com" or
     * "cognito-idp.us-east-1.amazonaws.com/us-east-1_abcdefghi:app_client_id".</p>
     */
    inline GetIdentityPoolRolesResult& WithRoleMappings(const Aws::Map<Aws::String, RoleMapping>& value) { SetRoleMappings(value); return *this;}

    /**
     * <p>How users for a specific identity provider are to mapped to roles. This is a
     * String-to-<a>RoleMapping</a> object map. The string identifies the identity
     * provider, for example, "graph.facebook.com" or
     * "cognito-idp.us-east-1.amazonaws.com/us-east-1_abcdefghi:app_client_id".</p>
     */
    inline GetIdentityPoolRolesResult& WithRoleMappings(Aws::Map<Aws::String, RoleMapping>&& value) { SetRoleMappings(std::move(value)); return *this;}

    /**
     * <p>How users for a specific identity provider are to mapped to roles. This is a
     * String-to-<a>RoleMapping</a> object map. The string identifies the identity
     * provider, for example, "graph.facebook.com" or
     * "cognito-idp.us-east-1.amazonaws.com/us-east-1_abcdefghi:app_client_id".</p>
     */
    inline GetIdentityPoolRolesResult& AddRoleMappings(const Aws::String& key, const RoleMapping& value) { m_roleMappings.emplace(key, value); return *this; }

    /**
     * <p>How users for a specific identity provider are to mapped to roles. This is a
     * String-to-<a>RoleMapping</a> object map. The string identifies the identity
     * provider, for example, "graph.facebook.com" or
     * "cognito-idp.us-east-1.amazonaws.com/us-east-1_abcdefghi:app_client_id".</p>
     */
    inline GetIdentityPoolRolesResult& AddRoleMappings(Aws::String&& key, const RoleMapping& value) { m_roleMappings.emplace(std::move(key), value); return *this; }

    /**
     * <p>How users for a specific identity provider are to mapped to roles. This is a
     * String-to-<a>RoleMapping</a> object map. The string identifies the identity
     * provider, for example, "graph.facebook.com" or
     * "cognito-idp.us-east-1.amazonaws.com/us-east-1_abcdefghi:app_client_id".</p>
     */
    inline GetIdentityPoolRolesResult& AddRoleMappings(const Aws::String& key, RoleMapping&& value) { m_roleMappings.emplace(key, std::move(value)); return *this; }

    /**
     * <p>How users for a specific identity provider are to mapped to roles. This is a
     * String-to-<a>RoleMapping</a> object map. The string identifies the identity
     * provider, for example, "graph.facebook.com" or
     * "cognito-idp.us-east-1.amazonaws.com/us-east-1_abcdefghi:app_client_id".</p>
     */
    inline GetIdentityPoolRolesResult& AddRoleMappings(Aws::String&& key, RoleMapping&& value) { m_roleMappings.emplace(std::move(key), std::move(value)); return *this; }

    /**
     * <p>How users for a specific identity provider are to mapped to roles. This is a
     * String-to-<a>RoleMapping</a> object map. The string identifies the identity
     * provider, for example, "graph.facebook.com" or
     * "cognito-idp.us-east-1.amazonaws.com/us-east-1_abcdefghi:app_client_id".</p>
     */
    inline GetIdentityPoolRolesResult& AddRoleMappings(const char* key, RoleMapping&& value) { m_roleMappings.emplace(key, std::move(value)); return *this; }

    /**
     * <p>How users for a specific identity provider are to mapped to roles. This is a
     * String-to-<a>RoleMapping</a> object map. The string identifies the identity
     * provider, for example, "graph.facebook.com" or
     * "cognito-idp.us-east-1.amazonaws.com/us-east-1_abcdefghi:app_client_id".</p>
     */
    inline GetIdentityPoolRolesResult& AddRoleMappings(const char* key, const RoleMapping& value) { m_roleMappings.emplace(key, value); return *this; }

  private:

    Aws::String m_identityPoolId;

    Aws::Map<Aws::String, Aws::String> m_roles;

    Aws::Map<Aws::String, RoleMapping> m_roleMappings;
  };

} // namespace Model
} // namespace CognitoIdentity
} // namespace Aws
