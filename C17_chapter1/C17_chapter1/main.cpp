
extern void structured_binding();
extern void if_switch_scope();
extern void init_braces_rules();
extern void ctor_auto_resolve_type();
extern void constexpr_if();
extern void header_libs_with_inline();
extern void fold_expression();

int main()
{
	structured_binding();
	if_switch_scope();
	init_braces_rules();
	ctor_auto_resolve_type();
	constexpr_if();
	header_libs_with_inline();
	fold_expression();
	return 0;
}