
#ifndef COMMON_MODULE_HOO
#define COMMON_MODULE_HOO

#include <ast.hpp>

namespace NG::module {
    using NG::ast::ASTRef;
    using NG::ast::ASTNode;

    struct IModuleLoader : NonCopyable {
        virtual ASTRef<ASTNode> load(const Str& module) = 0;

        virtual ~IModuleLoader()  = 0;
    };

    struct FileBasedExternalModuleLoader : public virtual IModuleLoader {

        ASTRef<NG::ast::ASTNode> load(const Str& module) override;

        ~FileBasedExternalModuleLoader() override;
    };
}

#endif //COMMON_MODULE_HOO
