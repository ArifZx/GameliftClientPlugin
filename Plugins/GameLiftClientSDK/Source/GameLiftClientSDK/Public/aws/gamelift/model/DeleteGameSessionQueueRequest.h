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
#include <aws/gamelift/GameLift_EXPORTS.h>
#include <aws/gamelift/GameLiftRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace GameLift
{
namespace Model
{

  /**
   * <p>Represents the input for a request action.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/gamelift-2015-10-01/DeleteGameSessionQueueInput">AWS
   * API Reference</a></p>
   */
  class AWS_GAMELIFT_API DeleteGameSessionQueueRequest : public GameLiftRequest
  {
  public:
    DeleteGameSessionQueueRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "DeleteGameSessionQueue"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>Descriptive label that is associated with game session queue. Queue names
     * must be unique within each region.</p>
     */
    inline const Aws::String& GetName() const{ return m_name; }

    /**
     * <p>Descriptive label that is associated with game session queue. Queue names
     * must be unique within each region.</p>
     */
    inline bool NameHasBeenSet() const { return m_nameHasBeenSet; }

    /**
     * <p>Descriptive label that is associated with game session queue. Queue names
     * must be unique within each region.</p>
     */
    inline void SetName(const Aws::String& value) { m_nameHasBeenSet = true; m_name = value; }

    /**
     * <p>Descriptive label that is associated with game session queue. Queue names
     * must be unique within each region.</p>
     */
    inline void SetName(Aws::String&& value) { m_nameHasBeenSet = true; m_name = std::move(value); }

    /**
     * <p>Descriptive label that is associated with game session queue. Queue names
     * must be unique within each region.</p>
     */
    inline void SetName(const char* value) { m_nameHasBeenSet = true; m_name.assign(value); }

    /**
     * <p>Descriptive label that is associated with game session queue. Queue names
     * must be unique within each region.</p>
     */
    inline DeleteGameSessionQueueRequest& WithName(const Aws::String& value) { SetName(value); return *this;}

    /**
     * <p>Descriptive label that is associated with game session queue. Queue names
     * must be unique within each region.</p>
     */
    inline DeleteGameSessionQueueRequest& WithName(Aws::String&& value) { SetName(std::move(value)); return *this;}

    /**
     * <p>Descriptive label that is associated with game session queue. Queue names
     * must be unique within each region.</p>
     */
    inline DeleteGameSessionQueueRequest& WithName(const char* value) { SetName(value); return *this;}

  private:

    Aws::String m_name;
    bool m_nameHasBeenSet;
  };

} // namespace Model
} // namespace GameLift
} // namespace Aws
