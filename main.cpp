#include <iostream>
#include <type_traits>
#include <cstdint>
#include <concepts>
#include <utility>

namespace cel::prm::flag {

    template<class Idx, Idx Val = dynamic_cast<Idx>(0x0)> requires std::is_integral_v<Idx>
    class Flag {

    public:
        using value_type = Idx;
        using type = Flag<Idx, Val>;
        using ref_type = Flag<Idx, Val> &;

    private:
        std::integral_constant<Idx, Val> value;

    public:
        constexpr Flag() noexcept = default;

        constexpr Flag(Flag const &) noexcept = default;

        constexpr Flag(Flag &&) noexcept = default;

        constexpr Flag &operator=(Flag const &) noexcept = default;

        constexpr Flag &operator=(Flag &&) noexcept = default;

        constexpr virtual ~Flag() noexcept = default;
    };
}

// std::rel_ops

namespace cel::prm::offset {

    template<class Idx, Idx Val = dynamic_cast<Idx>(0x0)> requires std::is_integral_v<Idx>
    class Offset {
        std::integral_constant<Idx, Val> value;

        public:
        constexpr Offset() noexcept = default;
        constexpr Offset(Offset const &) noexcept = default;
        constexpr Offset(Offset &&) noexcept = default;
        constexpr virtual ~Offset() noexcept = default;

        constexpr Offset &operator=(Offset const &) noexcept = default;
        constexpr Offset &operator=(Offset &&) noexcept = default;
    };
}

namespace cel::prm {

    template <class Tdx, class Rdx, template <t
    class TransformationParameters {

    private:
        template<typename Idx, Idx Val>
        using flag_t = cel::prm::flag::Flag<Idx, Val>;
        using flag = flag_t<std::uint8_t, 0x1>;
        friend flag;

    private:
        template <typename Idx, Idx Val>
        using offset_t = cel::prm::offset::Offset<Idx, Val>;
        using offset = offset_t<std::uint8_t, 0x1>;
        friend offset;

    private:    /* Fields */
        flag m_flag;
        offset m_offset;
        double phi0;
        double theta0;
        double ref[4];
        struct prjprm *prj;
        double euler[5];
        int latpreq;
        int isolat;
        struct wcserr *err;
    } __attribute__((aligned(0x8)));
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
