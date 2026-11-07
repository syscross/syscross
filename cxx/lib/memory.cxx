
module;

#include <memory>

export module memory;

export {
    using std::make_unique;
    using std::make_shared;

    template <typename... T>
    using unique = std::unique_ptr<T...>;

    template <typename... T>
    using shared = std::shared_ptr<T...>;

    template <typename... T>
    using weak = std::weak_ptr<T...>;
}
