#include "quickVtkPlatonicSolidSource.hpp"

namespace quick {

    namespace Vtk {

        Qml::Register::Symbol::Class<PlatonicSolidSource> PlatonicSolidSource::Register;

        PlatonicSolidSource::PlatonicSolidSource() : PolyDataAlgorithm(vtkSmartPointer<vtkPlatonicSolidSource>::New()) {
            this->m_vtkObject = vtkPlatonicSolidSource::SafeDownCast(Algorithm::getVtkObject());
        }

        auto PlatonicSolidSource::setSolidType(SolidType solidType) -> void {
            this->m_vtkObject->SetSolidType(solidType);
            this->update();
            emit this->solidTypeChanged();
        }

        auto PlatonicSolidSource::getSolidType() -> SolidType {
            return (SolidType) this->m_vtkObject->GetSolidType();
        }
    }
}
