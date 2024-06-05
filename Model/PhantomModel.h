////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief ���������� ������ PhantomModel
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once 

#include "IObservable.h"
#include "Model_fwd.h"
#include "../Geometry/GeometryPoint.h"

namespace model
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// ���������� ������ PhantomModel
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class PhantomModel : public IObservable
  {
  private:
    std::vector<UpdateFunc> m_callbacks; ///< �����������, ������� ���� ���������� �� ���������
    FigureUPtr m_figure; ///< ������
  public:
    /// ����������
    ~PhantomModel();
    /// ����� ���������� ������ � ��������� ������
    void SetTempFigure(FigureUPtr);
    /// ����� ��������� ������ �� ��������� ������
    const IFigure* GetTempFigure() const;
    /// ����������� ������ �� ��������� ������ � �������
    void TransferPhantomFigure(IModel&);
    /// �������� ��������� ������
    void CleanFigure();
    /// �������� ��������� �� �����������
    virtual void AddObserver(UpdateFunc) override;
    /// ��������� ����������� �� ��������� 
    virtual void Notify() const override;
  };

  /// ������� ������� ��������� ������
  std::unique_ptr<PhantomModel> CreatePhantomModel();
} // namespace model