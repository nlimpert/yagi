/*
 * ExecutableElementsContainer.h
 *
 *  Created on: Jul 17, 2014
 *      Author: cmaier
 */

#ifndef EXECUTABLEELEMENTSCONTAINER_H_
#define EXECUTABLEELEMENTSCONTAINER_H_

#include <unordered_map>
#include <map>
#include <string>

#include "../common/ASTNodeTypes/Declarations/ActionDecl/NodeActionDecl.h"
#include "../common/ASTNodeTypes/Declarations/ProcDecl/NodeProcDecl.h"
#include "../common/ASTNodeTypes/Declarations/ExogenousEventDecl/NodeExogenousEventDecl.h"

namespace yagi {
namespace execution {

class ExecutableElementsContainer
  final
  {
    private:
      ExecutableElementsContainer(ExecutableElementsContainer const&);
      void operator=(ExecutableElementsContainer const&);
      ExecutableElementsContainer();
      ~ExecutableElementsContainer();

      std::unordered_map<std::string, std::shared_ptr<NodeActionDecl>> actions_;
      std::unordered_map<std::string, std::shared_ptr<NodeProcDecl>> procedures_;
      std::unordered_map<std::string, std::shared_ptr<NodeExogenousEventDecl>> exoEvents_;

    public:
      static ExecutableElementsContainer& getInstance()
      {
        static ExecutableElementsContainer instance;
        return instance;
      }

      void addOrReplaceAction(const NodeActionDecl& actionDecl)
      {
        actions_[actionDecl.getActionName()->getId()] = std::make_shared<NodeActionDecl>(
            actionDecl);
      }

      std::shared_ptr<NodeActionDecl> getAction(const std::string& actionName)
      {
        auto val = actions_.find(actionName);
        if (val != std::end(actions_))
        {
          return actions_[actionName];
        }
        return nullptr;
      }

      void addOrReplaceProcedure(const NodeProcDecl& procDecl)
      {
        procedures_[procDecl.getProcName()->getId()] = std::make_shared<NodeProcDecl>(procDecl);
      }

      std::shared_ptr<NodeProcDecl> getProcedure(const std::string& actionName)
      {
        auto val = procedures_.find(actionName);
        if (val != std::end(procedures_))
        {
          return procedures_[actionName];
        }
        return nullptr;
      }

      void addOrReplaceExoEvent(const NodeExogenousEventDecl& exoEventDecl)
      {
        exoEvents_[exoEventDecl.getExogenousEventName()->getId()] = std::make_shared<
            NodeExogenousEventDecl>(exoEventDecl);
      }

      std::shared_ptr<NodeExogenousEventDecl> getExoEvent(const std::string& exoEventName)
      {
        if (exoEventExists(exoEventName))
        {
          return exoEvents_[exoEventName];
        }
        return nullptr;
      }

      bool exoEventExists(const std::string& exoEventName)
      {
        auto val = exoEvents_.find(exoEventName);
        if (val != std::end(exoEvents_))
        {
          return true;
        }

        return false;
      }
  };

  } /* namespace execution */
  } /* namespace yagi */

#endif /* EXECUTABLEELEMENTSCONTAINER_H_ */
