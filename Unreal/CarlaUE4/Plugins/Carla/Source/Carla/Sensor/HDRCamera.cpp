#include "Carla.h"
#include "Carla/Sensor/HDRCamera.h"

#include "Carla/Sensor/PixelReader.h"

FActorDefinition AHDRCamera::GetSensorDefinition()
{
  constexpr bool bEnableModifyingPostProcessEffects = true;
  return UActorBlueprintFunctionLibrary::MakeCameraDefinition(
      TEXT("hdr"),
      bEnableModifyingPostProcessEffects);
}

AHDRCamera::AHDRCamera(const FObjectInitializer &ObjectInitializer)
  : Super(ObjectInitializer)
{
  Enable16BitFormat(true);
  AddPostProcessingMaterial(
      TEXT("Material'/Carla/PostProcessingMaterials/PhysicLensDistortion.PhysicLensDistortion'"));
  CaptureRenderTarget->RenderTargetFormat = ETextureRenderTargetFormat::RTF_RGBA16f;
}

void AHDRCamera::PostPhysTick(UWorld *World, ELevelTick TickType, float DeltaSeconds)
{
  TRACE_CPUPROFILER_EVENT_SCOPE(AHDRCamera::PostPhysTick);
  FPixelReader::SendPixelsInRenderThread(*this, true, false);
}