/*++
Copyright (c) Microsoft Corporation

Module Name:
- Utf8CharRow.hpp

Abstract:
- contains data structure for UTF8 encoded character data of a row

Author(s):
- Austin Diviness (AustDi) 13-Feb-2018

Revision History:
--*/


#include "ICharRow.hpp"

#include <vector>

class Utf8CharRow final : public ICharRow
{
public:
    using value_type = std::pair<std::vector<char>, DbcsAttribute>;
    using iterator = std::vector<value_type>::iterator;
    using const_iterator = std::vector<value_type>::const_iterator;

    Utf8CharRow(short rowWidth);
    Utf8CharRow(const Utf8CharRow& a);
    Utf8CharRow& operator=(const Utf8CharRow& a);
    Utf8CharRow(Utf8CharRow&& a) noexcept;
    ~Utf8CharRow();

    void swap(Utf8CharRow& other) noexcept;

    // ICharRow methods
    ICharRow::SupportedEncoding GetSupportedEncoding() const noexcept override;
    size_t size() const noexcept override;
    HRESULT Resize(_In_ size_t const newSize) override;
    void Reset(_In_ short const sRowWidth) override;
    size_t MeasureLeft() const override;
    size_t MeasureRight() const override;
    void ClearCell(_In_ const size_t column) override;
    void SetWrapStatus(_In_ bool const fWrapWasForced) override;
    bool WasWrapForced() const override;
    bool ContainsText() const override;
    const DbcsAttribute& GetAttribute(_In_ const size_t column) const override;
    DbcsAttribute& GetAttribute(_In_ const size_t column) override;
    void SetDoubleBytePadded(_In_ bool const fDoubleBytePadded) override;
    bool WasDoubleBytePadded() const override;

    // iterators
    iterator begin() noexcept;
    const_iterator cbegin() const noexcept;

    iterator end() noexcept;
    const_iterator cend() const noexcept;


private:
    RowFlags bRowFlags;
    std::vector<value_type> _data;
};
