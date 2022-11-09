
//
// Template for this file generated with eicmkplugin.py
//

#include <JANA/JEventProcessorSequentialRoot.h>
#include <TH2.h>
#include <TFile.h>

#include <algorithms/tracking/JugTrack/Trajectories.hpp>
#include <algorithms/tracking/TrackProjector.h>
#include <extensions/spdlog/SpdlogMixin.h>
#include <edm4hep//MCParticle.h>
#include <edm4hep/SimTrackerHit.h>
#include <edm4eic/RawTrackerHit.h>
#include <edm4eic/TrackerHit.h>
#include <edm4eic/ReconstructedParticle.h>
#include <edm4eic/TrackSegment.h>
#include <edm4eic/TrackerHit.h>


class TofEfficiency_processor: public JEventProcessorSequentialRoot, public eicrecon::SpdlogMixin<TofEfficiency_processor>  {
private:

    // Data objects we will need from JANA
    // Since Prefetch<> is used as a fanction, we use function naming scheme for the next
    PrefetchT<edm4hep::MCParticle>  mcParticles   = {this, "MCParticles" };
    // PrefetchT<Jug::Trajectories>    Trajectories  = {this, "CentralCKFTrajectories"};
    PrefetchT<edm4eic::TrackSegment> trackSegments = {this, "CentralTrackSegments"};
    PrefetchT<edm4eic::TrackerHit> barrelHits = {this, "TOFBarrelTrackerHit"};
    PrefetchT<edm4eic::TrackerHit> endcapHits = {this, "TOFEndcapTrackerHit"};


    // Containers for histograms
    std::map<std::string, TH1*> m_1d_hists;
    std::map<std::string, TH2*> m_2d_hists;

public:
    TofEfficiency_processor() { SetTypeName(NAME_OF_THIS); }
    
    void InitWithGlobalRootLock() override;
    void ProcessSequential(const std::shared_ptr<const JEvent>& event) override;
    void FinishWithGlobalRootLock() override;

    TDirectory *m_dir_main;
};
