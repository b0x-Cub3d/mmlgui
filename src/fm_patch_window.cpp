#include "fm_patch_window.h"
#include "track_info.h"
#include "song.h"

FM_Patch_Window::FM_Patch_Window(std::shared_ptr<Song_Manager> song_mgr)
	: song_manager(song_mgr)
{
}

void FM_Patch_Window::display()
{
	// Draw window
	std::string window_id;
	window_id = "FM Patch Editor##" + std::to_string(id);

	ImGui::Begin(window_id.c_str(), &active);
	ImGui::SetWindowSize(ImVec2(600, 600), ImGuiCond_Once);

	// ctrmml stuff
	auto song = song_manager->get_song();
	auto platform = song->get_platform();	// defaults to megadrive anyways, but needed in the future.
	
	// registers, only based on the ym2612 for now.
	static int fb = 4;
	static int al = 4;
	static int ar1 = 31;
	static int dr1 = 0;
	static int sr1 = 0;
	static int rr1 = 7;
	static int sl1 = 0;
	static int tl1 = 32;
	static int ks1 = 0;
	static int ml1 = 0;
	static int dt1 = 0;
	static int ssg1 = 0;
	static bool ssg_eg1 = false;
	static bool am_mod1 = false;
	static int ar2 = 31;
	static int dr2 = 0;
	static int sr2 = 0;
	static int rr2 = 7;
	static int sl2 = 0;
	static int tl2 = 0;
	static int ks2 = 0;
	static int ml2 = 0;
	static int dt2 = 0;
	static int ssg2 = 0;
	static bool ssg_eg2 = false;
	static bool am_mod2 = false;
	static int ar3 = 31;
	static int dr3 = 0;
	static int sr3 = 0;
	static int rr3 = 7;
	static int sl3 = 0;
	static int tl3 = 32;
	static int ks3 = 0;
	static int ml3 = 0;
	static int dt3 = 0;
	static int ssg3 = 0;
	static bool ssg_eg3 = false;
	static bool am_mod3 = false;
	static int ar4 = 31;
	static int dr4 = 0;
	static int sr4 = 0;
	static int rr4 = 7;
	static int sl4 = 0;
	static int tl4 = 0;
	static int ks4 = 0;
	static int ml4 = 0;
	static int dt4 = 0;
	static int ssg4 = 0;
	static bool ssg_eg4 = false;
	static bool am_mod4 = false;

	
	// UI
	ImGui::SliderInt("Feedback", &fb, 0, 7, "%d");
	ImGui::SliderInt("Algorithm", &al, 0, 7, "%d");
	ImGui::Separator();
	/**********************************************************************/
	ImGui::Text("Operator 1");
    ImGui::VSliderInt("##int0", ImVec2(25, 100), &ar1, 0, 31,  "AR\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int1", ImVec2(25, 100), &dr1, 0, 31,  "DR\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int2", ImVec2(25, 100), &sr1, 0, 31,  "SR\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int3", ImVec2(25, 100), &rr1, 0, 15,  "RR\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int4", ImVec2(25, 100), &sl1, 0, 15,  "SL\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int5", ImVec2(25, 100), &tl1, 0, 127, "TL\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int6", ImVec2(25, 100), &ks1, 0, 3,   "KS\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int7", ImVec2(25, 100), &ml1, 0, 15,  "ML\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int8", ImVec2(25, 100), &dt1, 0, 7,   "DT\n%d");
	ImGui::SameLine();
	if(ssg_eg1){
		ImGui::VSliderInt("##int9", ImVec2(25, 100), &ssg1, 0, 7, "SSG\n%d");
		ImGui::SameLine();
	}
	ImGui::Checkbox("SSG-EG1 Enable", &ssg_eg1);
	ImGui::SameLine();
	ImGui::Checkbox("AM1 Enable", &am_mod1);
	ImGui::Separator();
	/**********************************************************************/
	ImGui::Text("Operator 2");
    ImGui::VSliderInt("##int10", ImVec2(25, 100), &ar2, 0, 31,  "AR\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int11", ImVec2(25, 100), &dr2, 0, 31,  "DR\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int12", ImVec2(25, 100), &sr2, 0, 31,  "SR\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int13", ImVec2(25, 100), &rr2, 0, 15,  "RR\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int14", ImVec2(25, 100), &sl2, 0, 15,  "SL\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int15", ImVec2(25, 100), &tl2, 0, 127, "TL\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int16", ImVec2(25, 100), &ks2, 0, 3,   "KS\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int17", ImVec2(25, 100), &ml2, 0, 15,  "ML\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int18", ImVec2(25, 100), &dt2, 0, 7,   "DT\n%d");
	ImGui::SameLine();
	if(ssg_eg2){
		ImGui::VSliderInt("##int19", ImVec2(25, 100), &ssg2, 0, 7, "SSG\n%d");
		ImGui::SameLine();
	}
	ImGui::Checkbox("SSG-EG2 Enable", &ssg_eg2);
	ImGui::SameLine();
	ImGui::Checkbox("AM2 Enable", &am_mod2);
	ImGui::Separator();
	/**********************************************************************/
	ImGui::Text("Operator 3");
    ImGui::VSliderInt("##int20", ImVec2(25, 100), &ar3, 0, 31,  "AR\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int21", ImVec2(25, 100), &dr3, 0, 31,  "DR\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int22", ImVec2(25, 100), &sr3, 0, 31,  "SR\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int23", ImVec2(25, 100), &rr3, 0, 15,  "RR\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int24", ImVec2(25, 100), &sl3, 0, 15,  "SL\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int25", ImVec2(25, 100), &tl3, 0, 127, "TL\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int26", ImVec2(25, 100), &ks3, 0, 3,   "KS\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int27", ImVec2(25, 100), &ml3, 0, 15,  "ML\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int28", ImVec2(25, 100), &dt3, 0, 7,   "DT\n%d");
	ImGui::SameLine();
	if(ssg_eg3){
		ImGui::VSliderInt("##int29", ImVec2(25, 100), &ssg3, 0, 7, "SSG\n%d");
		ImGui::SameLine();
	}
	ImGui::Checkbox("SSG-EG3 Enable", &ssg_eg3);
	ImGui::SameLine();
	ImGui::Checkbox("AM3 Enable", &am_mod3);
	ImGui::Separator();
	/**********************************************************************/
	ImGui::Text("Operator 4");
    ImGui::VSliderInt("##int30", ImVec2(25, 100), &ar4, 0, 31,  "AR\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int31", ImVec2(25, 100), &dr4, 0, 31,  "DR\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int32", ImVec2(25, 100), &sr4, 0, 31,  "SR\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int33", ImVec2(25, 100), &rr4, 0, 15,  "RR\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int34", ImVec2(25, 100), &sl4, 0, 15,  "SL\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int35", ImVec2(25, 100), &tl4, 0, 127, "TL\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int36", ImVec2(25, 100), &ks4, 0, 3,   "KS\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int37", ImVec2(25, 100), &ml4, 0, 15,  "ML\n%d");
	ImGui::SameLine();
	ImGui::VSliderInt("##int38", ImVec2(25, 100), &dt4, 0, 7,   "DT\n%d");
	ImGui::SameLine();
	if(ssg_eg4){
		ImGui::VSliderInt("##int39", ImVec2(25, 100), &ssg4, 0, 7, "SSG\n%d");
		ImGui::SameLine();
	}
	ImGui::Checkbox("SSG-EG4 Enable", &ssg_eg4);
	ImGui::SameLine();
	ImGui::Checkbox("AM4 Enable", &am_mod4);

	if (ImGui::Button("Copy")) {
		ImGui::SetClipboardText("Test.");
	}
	
	ImGui::End();
}
