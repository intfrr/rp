#include "ia32.hpp"
#include "rpexception.hpp"
#include "bearopgadgetfinder.hpp"

#include <cstring>
#include <list>

Ia32::Ia32(void)
{
}

Ia32::~Ia32(void)
{
}

std::string Ia32::get_class_name(void) const
{
    return std::string("Ia32");
}

std::multiset<Gadget*> Ia32::find_gadget_in_memory(const unsigned char *p_memory, const unsigned long long size, const unsigned long long vaddr, const unsigned int depth, unsigned int engine_display_option)
{  
    BeaRopGadgetFinder bea(BeaRopGadgetFinder::IA32, depth, engine_display_option);
    std::multiset<Gadget*> gadgets = bea.find_rop_gadgets(p_memory, size, vaddr);
    return gadgets;
}
