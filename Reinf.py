App.newDocument("BeamReinforcement")
Gui.activeDocument().activeView().viewDefaultOrientation()
import FreeCAD, Arch
from BeamReinforcement import TwoLeggedBeam

Structure = Arch.makeStructure(length=3000.0,width=228.60,height=457.20)
Structure.ViewObject.Transparency = 80
FreeCAD.ActiveDocument.recompute()

RebarGroup = TwoLeggedBeam.makeReinforcement(
    l_cover_of_stirrup=25,
    r_cover_of_stirrup=25,
    t_cover_of_stirrup=25,
    b_cover_of_stirrup=25,
    offset_of_stirrup=100,
    bent_angle=135,
    extension_factor=4,
    dia_of_stirrup=6,
    number_spacing_check=False,
    number_spacing_value=223.2819,
    
    top_reinforcement_number_diameter_offset=("2#25.0@0.0"),
    top_reinforcement_rebar_type="StraightRebar",
    top_reinforcement_layer_spacing=30,
    bottom_reinforcement_number_diameter_offset=("4#12@0","4#12@00"),
    bottom_reinforcement_rebar_type="StraightRebar",
    bottom_reinforcement_layer_spacing=25,
    left_rebars_number_diameter_offset="",
    left_rebars_type="StraightRebar",
    left_rebars_spacing=30,
    right_rebars_number_diameter_offset="",
    right_rebars_type="StraightRebar",
    right_rebars_spacing=30,
    top_reinforcement_l_rebar_rounding=2,
    top_reinforcement_hook_extension=100,
    top_reinforcement_hook_orientation="Rear Outside",
    bottom_reinforcement_l_rebar_rounding=2,
    bottom_reinforcement_hook_extension=100,
    bottom_reinforcement_hook_orientation="Rear Outside",
    left_l_rebar_rounding=2,
    left_rebars_hook_extension=80,
    left_rebars_hook_orientation=("Rear Inside", "Front Inside", "Rear Inside"),
    right_l_rebar_rounding=2,
    right_rebars_hook_extension=80,
    right_rebars_hook_orientation=("Front Inside", "Rear Inside", "Front Inside"),
    structure=Structure,
    facename="Face6",
)
