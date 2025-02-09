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
#include <aws/core/utils/memory/stl/AWSVector.h>
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
   * href="http://docs.aws.amazon.com/goto/WebAPI/gamelift-2015-10-01/DescribeMatchmakingRuleSetsInput">AWS
   * API Reference</a></p>
   */
  class AWS_GAMELIFT_API DescribeMatchmakingRuleSetsRequest : public GameLiftRequest
  {
  public:
    DescribeMatchmakingRuleSetsRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "DescribeMatchmakingRuleSets"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>List of one or more matchmaking rule set names to retrieve details for.
     * (Note: The rule set name is different from the optional "name" field in the rule
     * set body.) </p>
     */
    inline const Aws::Vector<Aws::String>& GetNames() const{ return m_names; }

    /**
     * <p>List of one or more matchmaking rule set names to retrieve details for.
     * (Note: The rule set name is different from the optional "name" field in the rule
     * set body.) </p>
     */
    inline bool NamesHasBeenSet() const { return m_namesHasBeenSet; }

    /**
     * <p>List of one or more matchmaking rule set names to retrieve details for.
     * (Note: The rule set name is different from the optional "name" field in the rule
     * set body.) </p>
     */
    inline void SetNames(const Aws::Vector<Aws::String>& value) { m_namesHasBeenSet = true; m_names = value; }

    /**
     * <p>List of one or more matchmaking rule set names to retrieve details for.
     * (Note: The rule set name is different from the optional "name" field in the rule
     * set body.) </p>
     */
    inline void SetNames(Aws::Vector<Aws::String>&& value) { m_namesHasBeenSet = true; m_names = std::move(value); }

    /**
     * <p>List of one or more matchmaking rule set names to retrieve details for.
     * (Note: The rule set name is different from the optional "name" field in the rule
     * set body.) </p>
     */
    inline DescribeMatchmakingRuleSetsRequest& WithNames(const Aws::Vector<Aws::String>& value) { SetNames(value); return *this;}

    /**
     * <p>List of one or more matchmaking rule set names to retrieve details for.
     * (Note: The rule set name is different from the optional "name" field in the rule
     * set body.) </p>
     */
    inline DescribeMatchmakingRuleSetsRequest& WithNames(Aws::Vector<Aws::String>&& value) { SetNames(std::move(value)); return *this;}

    /**
     * <p>List of one or more matchmaking rule set names to retrieve details for.
     * (Note: The rule set name is different from the optional "name" field in the rule
     * set body.) </p>
     */
    inline DescribeMatchmakingRuleSetsRequest& AddNames(const Aws::String& value) { m_namesHasBeenSet = true; m_names.push_back(value); return *this; }

    /**
     * <p>List of one or more matchmaking rule set names to retrieve details for.
     * (Note: The rule set name is different from the optional "name" field in the rule
     * set body.) </p>
     */
    inline DescribeMatchmakingRuleSetsRequest& AddNames(Aws::String&& value) { m_namesHasBeenSet = true; m_names.push_back(std::move(value)); return *this; }

    /**
     * <p>List of one or more matchmaking rule set names to retrieve details for.
     * (Note: The rule set name is different from the optional "name" field in the rule
     * set body.) </p>
     */
    inline DescribeMatchmakingRuleSetsRequest& AddNames(const char* value) { m_namesHasBeenSet = true; m_names.push_back(value); return *this; }


    /**
     * <p>Maximum number of results to return. Use this parameter with
     * <code>NextToken</code> to get results as a set of sequential pages.</p>
     */
    inline int GetLimit() const{ return m_limit; }

    /**
     * <p>Maximum number of results to return. Use this parameter with
     * <code>NextToken</code> to get results as a set of sequential pages.</p>
     */
    inline bool LimitHasBeenSet() const { return m_limitHasBeenSet; }

    /**
     * <p>Maximum number of results to return. Use this parameter with
     * <code>NextToken</code> to get results as a set of sequential pages.</p>
     */
    inline void SetLimit(int value) { m_limitHasBeenSet = true; m_limit = value; }

    /**
     * <p>Maximum number of results to return. Use this parameter with
     * <code>NextToken</code> to get results as a set of sequential pages.</p>
     */
    inline DescribeMatchmakingRuleSetsRequest& WithLimit(int value) { SetLimit(value); return *this;}


    /**
     * <p>Token that indicates the start of the next sequential page of results. Use
     * the token that is returned with a previous call to this action. To start at the
     * beginning of the result set, do not specify a value.</p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>Token that indicates the start of the next sequential page of results. Use
     * the token that is returned with a previous call to this action. To start at the
     * beginning of the result set, do not specify a value.</p>
     */
    inline bool NextTokenHasBeenSet() const { return m_nextTokenHasBeenSet; }

    /**
     * <p>Token that indicates the start of the next sequential page of results. Use
     * the token that is returned with a previous call to this action. To start at the
     * beginning of the result set, do not specify a value.</p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextTokenHasBeenSet = true; m_nextToken = value; }

    /**
     * <p>Token that indicates the start of the next sequential page of results. Use
     * the token that is returned with a previous call to this action. To start at the
     * beginning of the result set, do not specify a value.</p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::move(value); }

    /**
     * <p>Token that indicates the start of the next sequential page of results. Use
     * the token that is returned with a previous call to this action. To start at the
     * beginning of the result set, do not specify a value.</p>
     */
    inline void SetNextToken(const char* value) { m_nextTokenHasBeenSet = true; m_nextToken.assign(value); }

    /**
     * <p>Token that indicates the start of the next sequential page of results. Use
     * the token that is returned with a previous call to this action. To start at the
     * beginning of the result set, do not specify a value.</p>
     */
    inline DescribeMatchmakingRuleSetsRequest& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>Token that indicates the start of the next sequential page of results. Use
     * the token that is returned with a previous call to this action. To start at the
     * beginning of the result set, do not specify a value.</p>
     */
    inline DescribeMatchmakingRuleSetsRequest& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p>Token that indicates the start of the next sequential page of results. Use
     * the token that is returned with a previous call to this action. To start at the
     * beginning of the result set, do not specify a value.</p>
     */
    inline DescribeMatchmakingRuleSetsRequest& WithNextToken(const char* value) { SetNextToken(value); return *this;}

  private:

    Aws::Vector<Aws::String> m_names;
    bool m_namesHasBeenSet;

    int m_limit;
    bool m_limitHasBeenSet;

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet;
  };

} // namespace Model
} // namespace GameLift
} // namespace Aws
